// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginUI.h"

#include "LoginGameMode.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealClient/Global/ClientBlueprintFunctionLibrary.h"
#include "UnrealClient/Global/Message/ClientToServer.h"
#include "UnrealClient/Global/Message/GameServerMessage.h"

#include "SignInUIWidget.h"
#include "PopUpUIWidget.h"

void ULoginUI::NativeConstruct()
{
	m_ConnectStatusString = TEXT("UnConnected");
	m_ConnectedIconColor = FLinearColor(1.000000f,0.122189f,0.082387f,1.000000f);
	m_IPString = TEXT("127.0.0.1");
	m_PortString = TEXT("30001");

	m_SignInUIWidget = Cast<USignInUIWidget>(GetWidgetFromName("BP_SignInUI"));
	m_PopUpUIWidget =  Cast<UPopUpUIWidget>(GetWidgetFromName("BP_PopUpUI"));

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

	if(GameInst->GetIsClientMode())
	{
		return;		
	}
	
	std::string ID;
	std::string PW;
	UClientBlueprintFunctionLibrary::FStringToUTF8(m_IDString, ID);
	UClientBlueprintFunctionLibrary::FStringToUTF8(m_PWString, PW);

	LoginMessage Message;
	Message.m_ID = ID;
	Message.m_PW = PW;
	
	GameServerSerializer Serializer;
	Message.Serialize(Serializer);

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


void ULoginUI::SignInUIWidgetOpen()
{
	m_SignInUIWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void ULoginUI::SignInUIOff()
{
	m_SignInUIWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void ULoginUI::SignInFailedPopUpOn()
{
	m_PopUpUIWidget->SetVisibility(ESlateVisibility::Visible);
	m_PopUpUIWidget->SetPopUpMessageString(TEXT("SignIn Failed"));
}

void ULoginUI::SignInSucceedPopUpOn()
{
	m_PopUpUIWidget->SetVisibility(ESlateVisibility::Visible);
	m_PopUpUIWidget->SetPopUpMessageString(TEXT("SignIn Succeed"));

}

void ULoginUI::LoginFailedPopUpOn()
{
	m_PopUpUIWidget->SetVisibility(ESlateVisibility::Visible);
	m_PopUpUIWidget->SetPopUpMessageString(TEXT("Login Failed"));
}

