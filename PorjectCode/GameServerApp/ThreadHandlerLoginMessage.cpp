#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>

ThreadHandlerLoginMessage::ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage)
{
	m_TCPSession = _TCPSession;
	m_LoginMessage = _LoginMessage;
}

ThreadHandlerLoginMessage::~ThreadHandlerLoginMessage()
{

}

void ThreadHandlerLoginMessage::Start()
{
	if (m_TCPSession == nullptr)
	{
		GameServerDebug::LogError("Login TCPSession is Nullptr");
		return;
	}
	m_LoginResultMessage.m_LoginResultType = ELoginResultType::OK;


	ResultSend();
	
}

void ThreadHandlerLoginMessage::DBCheck()
{

}

void ThreadHandlerLoginMessage::ResultSend()
{
	//std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	//GameServerString::UTF8ToAnsi(LoginMessage_->ID, NewUser->ID);
	//
	//TCPSession_->SetLink(NewUser);

	GameServerSerializer Serializer;
	m_LoginResultMessage.Serialize(Serializer);

	m_TCPSession->Send(Serializer.GetData());

	GameServerDebug::LogInfo("Login Result Send");
}