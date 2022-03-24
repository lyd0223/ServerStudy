#pragma once

#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

/*
Usage		:
Category	:
Description :  ȸ������ ��Ŷ�� ���� ó���ؾ��� ������ ����.
*/

class ThreadHandlerSignInMessage final
	: public std::enable_shared_from_this<ThreadHandlerSignInMessage>
{
private:
	//��Ŷ�� ���� ����
	std::shared_ptr<TCPSession> m_TCPSession;

	//�� ��Ŷ
	std::shared_ptr<SignInMessage> m_SignInMessage;

	//��� ��Ŷ
	SignInResultMessage m_SignInResultMessage;

public: //Default
	ThreadHandlerSignInMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<SignInMessage> _SignInMessage);
	~ThreadHandlerSignInMessage();

	ThreadHandlerSignInMessage(const ThreadHandlerSignInMessage& _Other) = delete;
	ThreadHandlerSignInMessage(ThreadHandlerSignInMessage&& _Other)		noexcept = delete;

	ThreadHandlerSignInMessage& operator=(const ThreadHandlerSignInMessage& _Other) = delete;
	ThreadHandlerSignInMessage& operator=(ThreadHandlerSignInMessage&& _Other) = delete;


public:
	//�޽��� �޾����� �����ϴ� �Լ�.
	void Start();

private:
	void DBCheck();
	void ResultSend();

};

