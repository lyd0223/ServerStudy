#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

/*
Usage		:
Category	:
Description :  ä�� ��Ŷ�� ���� ó���ؾ��� ������ ����.
*/

class ThreadHandlerChatMessage final
	: public std::enable_shared_from_this<ThreadHandlerChatMessage>
{
private:
	//��Ŷ�� ���� ����
	std::shared_ptr<TCPSession> m_TCPSession;

	//�� ��Ŷ
	std::shared_ptr<ChatMessage> m_ChatMessage;

	//��� ��Ŷ
	LoginResultMessage m_LoginResultMessage;

public: //Default
	ThreadHandlerChatMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<ChatMessage> _ChatMessage);
	~ThreadHandlerChatMessage();

	ThreadHandlerChatMessage(const ThreadHandlerChatMessage& _Other) = delete;
	ThreadHandlerChatMessage(ThreadHandlerChatMessage&& _Other)		noexcept = delete;

protected:
	ThreadHandlerChatMessage& operator=(const ThreadHandlerChatMessage& _Other) = delete;
	ThreadHandlerChatMessage& operator=(ThreadHandlerChatMessage&& _Other) = delete;


public:
	//�޽��� �޾����� �����ϴ� �Լ�.
	void Start();

private:
	void ResultSend();

};