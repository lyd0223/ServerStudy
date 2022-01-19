#include "PreCompile.h"
#include "TCPListener.h"


TCPListener::TCPListener()
{

}

TCPListener::~TCPListener()
{

}

TCPListener::TCPListener(TCPListener&& _Other) noexcept
{

}

bool TCPListener::Init(const IPEndPoint& _EndPoint, const std::function<void(std::shared_ptr<class TCPSession>)>& _AcceptCallBack)
{

}

bool TCPListener::BindQueue(const class GameServerQueue& _JobQueue)
{

}

bool TCPListener::StartAccept(int _BackLogCount)
{

}

void TCPListener::Close()
{

}

void TCPListener::AsyncAccept()
{

}

void TCPListener::OnAccept(IOCPWaitReturnType _IOCPWaitReturnType, DWORD _Bytes, LPOVERLAPPED _OverLapped)
{
	}

bool TCPListener::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}