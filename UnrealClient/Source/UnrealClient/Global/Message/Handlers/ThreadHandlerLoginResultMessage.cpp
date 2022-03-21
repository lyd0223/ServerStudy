#include "ThreadHandlerLoginResultMessage.h"

#include "Kismet/GameplayStatics.h"


ThreadHandlerLoginResultMessage::ThreadHandlerLoginResultMessage(std::shared_ptr<LoginResultMessage> _LoginResultMessage)
{
	m_LoginResultMessage = _LoginResultMessage;
}

void ThreadHandlerLoginResultMessage::Init(UClientGameInstance* _GameInstance, UWorld* _World)
{
	m_GameInstance = _GameInstance;
	m_World = _World;
}

void ThreadHandlerLoginResultMessage::Start()
{
	if(m_LoginResultMessage->m_LoginResultType == ELoginResultType::OK)
	{
		UGameplayStatics::OpenLevel(m_World, TEXT("MainLevel"));
		
	}
}


