// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginUI.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealClient/Global/ClientBlueprintFunctionLibrary.h"
#include "UnrealClient/Global/Message/GameServerMessages.h"

void ULoginUI::NativeConstruct()
{
	m_ConnectStatusString = TEXT("UnConnected");
	m_ConnectedIconColor = FLinearColor(1.000000f,0.122189f,0.082387f,1.000000f);
	m_IPString = TEXT("127.0.0.1");
	m_PortString = TEXT("30001");
}

void ULoginUI::ServerConnect()
{
	// GetWorld() Level
	UGameplayStatics::GetPlayerController(GetWorld(), 0);
	

	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());

	// GameInst->GetLatentActionManager();

	if (false == GameInst->ServerConnect(m_IPString, m_PortString))
	{
		return;
	}

	m_ConnectStatusString = TEXT("Connected");
	m_ConnectedIconColor = FLinearColor(0.091802f,1.000000f,0.000000f,1.000000f);
}

void ULoginUI::ServerLogin() 
{
	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());
	
	std::string ID;
	std::string PW;
	UClientBlueprintFunctionLibrary::FStringToUTF8(m_IDString, ID);
	UClientBlueprintFunctionLibrary::FStringToUTF8(m_PWString, PW);

	LoginMessage Msg;
	Msg.SetID(ID);
	Msg.SetPW(PW);
	GameServerSerializer Serializer;
	Msg.Serialize(Serializer);
	
	if (GameInst->Send(Serializer.GetData()))
	{
		
	}
}

void ULoginUI::SetLocalIP()
{
	m_IPString = TEXT("127.0.0.1");
	m_PortString = TEXT("30001");
}

void ULoginUI::SetTeacherIP()
{
	m_IPString = TEXT("127.0.0.1");
	m_PortString = TEXT("30001");
}