#pragma once

#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

/*
Usage		:
Category	:
Description :  회원가입 패킷이 오면 처리해야할 동작을 구현.
*/

class ThreadHandlerSignInMessage final
	: public std::enable_shared_from_this<ThreadHandlerSignInMessage>
{
private:
	//패킷을 보낸 세션
	std::shared_ptr<TCPSession> m_TCPSession;

	//온 패킷
	std::shared_ptr<SignInMessage> m_SignInMessage;

	//결과 패킷
	SignInResultMessage m_SignInResultMessage;

public: //Default
	ThreadHandlerSignInMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<SignInMessage> _SignInMessage);
	~ThreadHandlerSignInMessage();

	ThreadHandlerSignInMessage(const ThreadHandlerSignInMessage& _Other) = delete;
	ThreadHandlerSignInMessage(ThreadHandlerSignInMessage&& _Other)		noexcept = delete;

	ThreadHandlerSignInMessage& operator=(const ThreadHandlerSignInMessage& _Other) = delete;
	ThreadHandlerSignInMessage& operator=(ThreadHandlerSignInMessage&& _Other) = delete;


public:
	//메시지 받았을때 실행하는 함수.
	void Start();

private:
	void DBCheck();
	void ResultSend();

};

