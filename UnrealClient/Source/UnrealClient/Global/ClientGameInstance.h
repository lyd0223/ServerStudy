// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <vector>

#include "ClientGameInstance.generated.h"


class GameServerMessage;

class UnrealRecvThread : public FRunnable
{
private:
	FSocket* m_RecvSocket;
	TAtomic<bool> m_IsAppClosed;

	TQueue<std::shared_ptr<GameServerMessage>, EQueueMode::Spsc>* m_MessageQueue;

public:
	UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* _MessageQueue);

	static bool FunctionTest();

	virtual uint32 Run() override;

	void Close();
};

UCLASS()
class UNREALCLIENT_API UClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TQueue<std::shared_ptr<GameServerMessage>> m_MessageQueue;
	UnrealRecvThread* m_RecvThread;
	FRunnableThread* m_ThreadRunalbe;

	ISocketSubsystem* m_SocketSubSystem;
	FSocket* m_Socket;

	//셀프 패킷 실험용으로 클라이언트 모드를 만들어놓음.
	bool m_IsClientMode;

public:
	UClientGameInstance();
	virtual ~UClientGameInstance() override;

public:
	bool GetIsClientMode() const
	{
		return m_IsClientMode;
	}

	void SetIsClientMode(bool _IsClientMode)
	{
		m_IsClientMode = _IsClientMode;
	}

	bool IsEmptyMessage() const
	{
		return m_MessageQueue.IsEmpty();
	}

public:
	bool ServerConnect(const FString& _IPString, const FString& _PortString);

	void PushClientMessage(std::shared_ptr<GameServerMessage> _Message);

	std::shared_ptr<GameServerMessage> PopMessage();

	bool Send(const std::vector<uint8>& _Data);

	void Close();

	

	virtual void FinishDestroy() override;

	bool IsThreadCheck();
};
