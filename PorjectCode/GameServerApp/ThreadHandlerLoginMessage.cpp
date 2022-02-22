#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>

ThreadHandlerLoginMessage::ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage)
{

}

ThreadHandlerLoginMessage::ThreadHandlerLoginMessage()
{

}

ThreadHandlerLoginMessage::~ThreadHandlerLoginMessage()
{

}

ThreadHandlerLoginMessage::ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept
{

}

void ThreadHandlerLoginMessage::Start()
{
	if (m_TCPSession == nullptr)
	{
		GameServerDebug::LogError("Login TCPSession is Nullptr");
		return;
	}
	m_LoginResultMessage.m_LoginResultType = ELoginResultType::Error;
	
}

void ThreadHandlerLoginMessage::End()
{

}