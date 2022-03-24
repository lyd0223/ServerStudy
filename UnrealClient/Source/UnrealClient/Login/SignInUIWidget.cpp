

#include "SignInUIWidget.h"
#include "PopUpUIWidget.h"
#include <string>
#include "../Global/ClientGameInstance.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "UnrealClient/Global/Message/ClientToServer.h"

void USignInUIWidget::NativeConstruct()
{
	
}

void USignInUIWidget::SignIn()
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

	SignInMessage Message;
	Message.m_ID = ID;
	Message.m_PW = PW;
	
	GameServerSerializer Serializer;
	Message.Serialize(Serializer);
	
	if (!GameInst->Send(Serializer.GetData()))
	{
		UE_LOG(LogTemp, Error, TEXT("SignInMessage Send Error"));
	}
}