// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientGameInstance.h"
#include "Sockets.h"
#include "SocketSubSystem.h"
#include "Networking.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Message/MessageConverter.h"

UnrealRecvThread::UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* _MessageQueue) 
{
	if (nullptr == _RecvSocket)
	{
		UE_LOG(LogTemp, Error, TEXT("RecvSocket Error"));
	}

	
	m_RecvSocket = _RecvSocket;
	m_IsAppClosed = false;
	m_MessageQueue = _MessageQueue;
}

bool UnrealRecvThread::FunctionTest() 
{
	return false;
}

uint32 UnrealRecvThread::Run() 
{
	UE_LOG(LogTemp, Log, TEXT("Recv Start"));

	while (!m_IsAppClosed)
	{

		std::vector<uint8> RecvData;
		RecvData.resize(1024);
		int32 RecvDataSize_ = 0;

		//서버 접속체크
		if (false == m_RecvSocket->Recv(&RecvData[0], RecvData.size(), RecvDataSize_))
		{
			auto Result = m_RecvSocket->GetConnectionState();

			switch(Result)
			{
			case ESocketConnectionState::SCS_NotConnected:
				break;
			case ESocketConnectionState::SCS_Connected: 
				{
					ServerDestroyMessage Message;
					GameServerSerializer Serializer;
					Message.Serialize(Serializer);

					MessageConverter Converter = MessageConverter(Serializer.GetData());
					m_MessageQueue->Enqueue(Converter.GetServerMessage());
					return 0;
				}

				break;
			case ESocketConnectionState::SCS_ConnectionError:
				break;
				
			}
			break;
		}

		MessageConverter Converter = MessageConverter(RecvData);
		m_MessageQueue->Enqueue(Converter.GetServerMessage());

	}

	return 0;
}

void UnrealRecvThread::Close()
{
	m_IsAppClosed = true;
}

UClientGameInstance::UClientGameInstance()
{
	m_IsClientMode = false;
}

UClientGameInstance::~UClientGameInstance() 
{
	if(m_RecvThread)
	{
		m_RecvThread->Exit();
		m_RecvThread = nullptr;
	}
}

void UClientGameInstance::Close() 
{
	if(m_RecvThread)
	{
		m_RecvThread->Close();
	}
	
	if (m_Socket == nullptr)
	{
		return;
	}

	m_Socket->Close();
	m_Socket = nullptr;
}

bool UClientGameInstance::ServerConnect(const FString& _IPString, const FString& _PORTString)
{
	if (IsThreadCheck() == false)
	{
		return false;
	}

	Close();

	m_SocketSubSystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	// 이 Level Login Level에서 만들어졌다고 치고

	m_Socket = m_SocketSubSystem->CreateSocket(NAME_Stream, "Test", false);

	if (nullptr == m_Socket)
	{
		UE_LOG(LogTemp, Error, TEXT("if (nullptr == NewSocket)"));
		return false;
	}

	m_Socket ->SetNoDelay(true);

	FIPv4Address ConnectAddress;
	FIPv4Address::Parse(_IPString, ConnectAddress);
	int Port = static_cast<uint16>(FCString::Atoi(*_PORTString));
	FIPv4Endpoint EndPoint = FIPv4Endpoint(ConnectAddress, Port);
	
	if (false == m_Socket->Connect(EndPoint.ToInternetAddr().Get()))
	{
		m_SocketSubSystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
		FString ErrorText = m_SocketSubSystem->GetSocketError(m_SocketSubSystem->GetLastErrorCode());
		
		UE_LOG(LogTemp, Error, TEXT("Server Error : %s"), *ErrorText);
		m_Socket->Close();
		m_Socket = nullptr;
		return false;
	}

	//TCP소켓 노딜레이옵션.
	m_Socket->SetNoDelay(true);
	
	m_RecvThread = new UnrealRecvThread(m_Socket, &m_MessageQueue);
	m_ThreadRunalbe = FRunnableThread::Create(m_RecvThread, TEXT("Recv Thread"));
	
	return true;
}

//플랫폼에서 멀티프로세스를 지원하는지 체크하는 함수.
bool UClientGameInstance::IsThreadCheck() 
{
	if (false == FPlatformProcess::SupportsMultithreading())
	{
		UE_LOG(LogTemp, Error, TEXT("Is Not Support Multithreading"));
		return false;
	}

	return true;
}

bool UClientGameInstance::Send(const std::vector<uint8>& _Data)
{
	if(m_Socket == nullptr)
	{
		return false;
	}
	if (0 == _Data.size())
	{
		return false;
	}

	int32 DataSendSize = 0;

	return m_Socket->Send(&_Data[0], _Data.size(), DataSendSize);
}

//클라이언트모드 전용푸시함수.
void UClientGameInstance::PushClientMessage(std::shared_ptr<GameServerMessage> _Message)
{
	if(m_IsClientMode)
		return;

	m_MessageQueue.Enqueue(_Message);
}

std::shared_ptr<GameServerMessage> UClientGameInstance::PopMessage()
{
	std::shared_ptr<GameServerMessage> Message;
	m_MessageQueue.Dequeue(Message);

	return Message;
}


void UClientGameInstance::FinishDestroy()
{
	Close();

	Super::FinishDestroy();
}
