#include "PreCompile.h"
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <thread>
#include <conio.h>

#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerIocp.h>
#include <GameServerBase/GameServerQueue.h>
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerSerializer.h>
#include <GameServerBase/GameServerString.h>

#include <GameServerNet/TCPListener.h>
#include <GameServerNet/TCPSession.h>
#include <GameServerNet/ServerHelper.h>

#include <GameServerMessage/GameServerMessages.h>
#include <GameServerMessage/Dispatcher.h>
#include <GameServerMessage/MessageConverter.h>

#include "ThreadLoginMessage.h"
#include "NetQueue.h"
#include "DBQueue.h"

template<class ThreadMessage, class MessageType>
void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<Message> _Message)
{
	std::shared_ptr<MessageType> ConvertMessage = std::dynamic_pointer_cast<MessageType>(_Message);
	
	if (ConvertMessage == nullptr)
	{
		GameServerDebug::LogError("LoginMessage Convert Error");
		return;
	}
	
	std::shared_ptr<ThreadMessage> cmd = std::make_shared<ThreadMessage>(_Session, ConvertMessage);
	cmd->Start();
}

Dispatcher<TCPSession> gDispatcher;

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	NetQueue::Initialize();
	DBQueue::Initialize();

	gDispatcher.AddHandler(static_cast<uint32_t>(EMessageType::Login), std::bind(&OnMessageProcess<ThreadLoginMessage,LoginMessage>, std::placeholders::_1, std::placeholders::_2));
	
	ServerHelper::StartEngineStartUp();
	GameServerDebug::Initialize();

	PtrSTCPListener NewListener = std::make_shared<TCPListener>();

	NewListener->Initialize(IPEndPoint(IPAddress::Parse("0.0.0.0"), 30001), [](PtrSTCPSession _S)
		{
			
			_S->SetCallBack(
				//Packet받았을떄 CallBack
				[&](PtrSTCPSession _S, const std::vector<unsigned char>& _Value)
				{
					MessageConverter Converter = MessageConverter(_Value);
				
					MessageHandler<TCPSession> Handler;
					bool check = gDispatcher.GetHandler(Converter.GetMessageTypeByuint(), Handler);
					if (!check)
					{
						GameServerDebug::LogError("GetHandler Error");
						return;
					}
					Handler(_S, Converter.GetServerMessage());
				},
				//Socket연결끊겼을때 CallBack
				[](PtrSTCPSession _S)
				{
					std::string LogText = std::to_string(static_cast<int>(_S->GetSocket()));
					GameServerDebug::LogInfo(LogText + "접속자가 접속을 종료했습니다.");
				});


			std::string LogText = std::to_string(static_cast<int>(_S->GetSocket()));

			GameServerDebug::LogInfo(LogText + "접속자가 있습니다.");
		}
	);

	NewListener->BindQueue(NetQueue::GetQueue());
	NewListener->StartAccept(10);
	
	GameServerDebug::LogInfo("서버 시작.");

	
	while (1)
	{
		int a = 0;
	}

	NetQueue::Destroy();
	DBQueue::Destroy();

	GameServerDebug::Destroy();
}