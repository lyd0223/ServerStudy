#pragma once
#include "IPEndPoint.h"
/*
Usage		:  TCP 접속 받는 용도
Category	:  
Description :  TCP 접속 받는 용도.
*/


class TCPListener
{
public: //Default
	TCPListener();
	~TCPListener();

	TCPListener(const TCPListener& _Other) = delete;
	TCPListener(TCPListener&& _Other)		noexcept;

public:
	bool Init(const IPEndPoint& _EndPoint, const std::function<void(std::shared_ptr<class TCPSession>)>& _AcceptCallBack);
	
	bool BindQueue(const class GameServerQueue& _JobQueue);
	
	bool StartAccept(int _BackLogCount);

	void Close();
	
protected:
	TCPListener& operator=(const TCPListener& _Other) = delete;
	TCPListener& operator=(TCPListener&& _Other)		= delete;

protected:
	void AsyncAccept();

private: //Member Value
	SOCKET m_ListenSocket;
	IPEndPoint m_ListenEndPoint;
	const class GameServerQueue* m_JobQueue;
	
	std::function<void(std::shared_ptr<TCPSession>)> m_AcceptCallBack;
	
	std::mutex m_SessionPoolLock;
	std::queue<std::shared_ptr<TCPSession>> m_SessionPool;
	
private:
	void OnAccept(IOCPWaitReturnType _IOCPWaitReturnType, DWORD _Bytes, LPOVERLAPPED _OverLapped);
	
	
public:  //Member Function
	bool IsValid();
};

