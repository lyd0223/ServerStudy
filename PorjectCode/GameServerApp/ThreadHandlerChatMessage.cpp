
#include "PreCompile.h"
#include "ThreadHandlerChatMessage.h"
#include <GameServerBase/GameServerDebug.h>

ThreadHandlerChatMessage::ThreadHandlerChatMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<ChatMessage> _ChatMessage)
{
	m_TCPSession = _TCPSession;
	m_ChatMessage = _ChatMessage;
}

ThreadHandlerChatMessage::~ThreadHandlerChatMessage()
{

}

void ThreadHandlerChatMessage::Start()
{
	
	
}


void ThreadHandlerChatMessage::ResultSend()
{

}