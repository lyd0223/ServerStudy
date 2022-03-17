#include "ThreadHandlerChatMessage.h"

#include "Kismet/GameplayStatics.h"


ThreadHandlerChatMessage::ThreadHandlerChatMessage(std::shared_ptr<ChatMessage> _ChatMessage)
{
	m_ChatMessage = _ChatMessage;
}

void ThreadHandlerChatMessage::Init(UClientGameInstance* _GameInstance, UWorld* _World)
{
	m_GameInstance = _GameInstance;
	m_World = _World;
}

void ThreadHandlerChatMessage::Start()
{
	
}


