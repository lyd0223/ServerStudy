#include "PreCompile.h"
#include "ThreadLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>

ThreadLoginMessage::ThreadLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage)
{

}

ThreadLoginMessage::ThreadLoginMessage()
{

}

ThreadLoginMessage::~ThreadLoginMessage()
{

}

ThreadLoginMessage::ThreadLoginMessage(ThreadLoginMessage&& _Other) noexcept
{

}

void ThreadLoginMessage::Start()
{
	if (m_TCPSession == nullptr)
	{
		GameServerDebug::LogError("Login TCPSession is Nullptr");
		return;
	}
	m_LoginResultMessage.m_ResultType = ELoginResultType::Error;
	
}

void ThreadLoginMessage::End()
{

}