// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <string>
#include <vector>
#include "ClientGameInstance.generated.h"

// std::thread
// ��� �ڵ带 ������Ѽ� ó������ �����Ҽ� ����?
class UnrealRecvThread : public FRunnable 
{
private:
	FSocket* m_RecvSocket;

public:
	UnrealRecvThread(FSocket* m_RecvSocket);

	static bool FunctionTest();

	uint32 Run() override;
	void Stop() override;
	void Exit() override;
};

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	UnrealRecvThread* m_RecvThread;
	FRunnableThread* m_ThreadRunalbe;

	ISocketSubsystem* m_SocketSubSystem;
	FSocket* m_Socket;

public:
	UClientGameInstance();
	~UClientGameInstance();


	bool IsThreadCheck();
	bool IsGameCheck();

	bool ServerConnect(const FString& _IPString, const FString& _PortString);
	void Close();

	bool Send(const std::vector<uint8>& _Data);
	//bool Recv();
};
