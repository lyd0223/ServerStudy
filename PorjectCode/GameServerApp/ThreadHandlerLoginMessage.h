#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

/*
Usage		:  
Category	:  
Description :  
*/

class ThreadHandlerLoginMessage final 
	: public std::enable_shared_from_this<ThreadHandlerLoginMessage>
{
private:
	//��Ŷ�� ���� ����
	std::shared_ptr<TCPSession> m_TCPSession;
	
	//�� ��Ŷ
	std::shared_ptr<LoginMessage> m_LoginMessage;

	//��� ��Ŷ
	LoginResultMessage m_LoginResultMessage;

public: //Default
	ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage);
	ThreadHandlerLoginMessage();
	~ThreadHandlerLoginMessage();

	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other)		noexcept;

protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other)		= delete;


public:
	//�޽��� �޾����� �����ϴ� �Լ�.
	void Start();

private: //Member Value
	void End();
	
};

