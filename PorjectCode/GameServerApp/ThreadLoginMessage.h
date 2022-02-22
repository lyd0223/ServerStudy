#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/GameServerMessages.h>

/*
Usage		:  
Category	:  
Description :  
*/

class ThreadLoginMessage final 
	: public std::enable_shared_from_this<ThreadLoginMessage>
{
private:
	//��Ŷ�� ���� ����
	std::shared_ptr<TCPSession> m_TCPSession;
	
	//�� ��Ŷ
	std::shared_ptr<LoginMessage> m_LoginMessage;

	//��� ��Ŷ
	LoginResultMessage m_LoginResultMessage;

public: //Default
	ThreadLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage);
	ThreadLoginMessage();
	~ThreadLoginMessage();

	ThreadLoginMessage(const ThreadLoginMessage& _Other) = delete;
	ThreadLoginMessage(ThreadLoginMessage&& _Other)		noexcept;

protected:
	ThreadLoginMessage& operator=(const ThreadLoginMessage& _Other) = delete;
	ThreadLoginMessage& operator=(ThreadLoginMessage&& _Other)		= delete;


public:
	//�޽��� �޾����� �����ϴ� �Լ�.
	void Start();

private: //Member Value
	void End();
	
};

