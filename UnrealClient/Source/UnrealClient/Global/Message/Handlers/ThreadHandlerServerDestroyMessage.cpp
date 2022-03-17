#include "ThreadHandlerServerDestroyMessage.h"

#include "Kismet/GameplayStatics.h"


ThreadHandlerServerDestroyMessage::ThreadHandlerServerDestroyMessage(std::shared_ptr<ServerDestroyMessage> _ServerDestroyMessage)
{
	m_ServerDestroyMessage = _ServerDestroyMessage;
}

void ThreadHandlerServerDestroyMessage::Init(UClientGameInstance* _GameInstance, UWorld* _World)
{
	m_GameInstance = _GameInstance;
	m_World = _World;
}

void ThreadHandlerServerDestroyMessage::Start()
{
	if(m_World->GetName() != TEXT("LoginLevel"))
	{
		UGameplayStatics::OpenLevel(m_World, TEXT("LoginLevel"));
	}
}


