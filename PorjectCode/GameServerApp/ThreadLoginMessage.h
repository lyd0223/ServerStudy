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
	//패킷을 보낸 세션
	std::shared_ptr<TCPSession> m_TCPSession;
	
	//온 패킷
	std::shared_ptr<LoginMessage> m_LoginMessage;

	//결과 패킷
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
	//메시지 받았을때 실행하는 함수.
	void Start();

private: //Member Value
	void End();
	
};

