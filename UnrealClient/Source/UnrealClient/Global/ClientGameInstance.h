// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <vector>
#include "ClientGameInstance.generated.h"


class Message;
class UnrealRecvThread : public FRunnable
{
private:
	FSocket* m_RecvSocket;
	TAtomic<bool> m_IsAppClosed;

	TQueue<std::shared_ptr<Message>, EQueueMode::Spsc>* m_MessageQueue;

public:
	UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<Message>, EQueueMode::Spsc>* _MessageQueue);

	static bool FunctionTest();

	uint32 Run() override;

	void Close();
};

UCLASS()
class UNREALCLIENT_API UClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TQueue<std::shared_ptr<Message>> m_MessaeQueue;
	UnrealRecvThread* m_RecvThread;
	FRunnableThread* m_ThreadRunalbe;

	ISocketSubsystem* m_SocketSubSystem;
	FSocket* m_Socket;

	//셀프 패킷 실험용으로 클라이언트 모드를 만들어놓음.
	bool m_IsClientMode;

public:
	bool GetIsClientMode() const
	{
		return m_IsClientMode;
	}
	void SetIsClientMode(bool _IsClientMode)
	{
		m_IsClientMode = _IsClientMode;
	}
	
public:
	UClientGameInstance();
	~UClientGameInstance();

	void PushClientMessage(std::shared_ptr<Message> _Message);

	std::shared_ptr<Message> PopMessage();
	bool IsEmptyMessage();;
	
	bool IsThreadCheck();
	bool IsGameCheck();

	bool ServerConnect(const FString& _IPString, const FString& _PortString);
	void Close();

	bool Send(const std::vector<uint8>& _Data);

	void FinishDestroy() override;
};
