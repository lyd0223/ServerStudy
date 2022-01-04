#include "PreCompile.h"
#include "GameServerIOCP.h"
#include "GameServerThread.h"
#include "GameServerDebug.h"

GameServerThreadWorker::GameServerThreadWorker(HANDLE _IOCPHandle, int _Index, DWORD _Time)
	:m_IOCPHandle(_IOCPHandle),
	m_Index(_Index),
	m_Time(_Time)
{

}

IOCPWaitReturnType GameServerThreadWorker::Wait()
{
	m_LastWaitValue = GetQueuedCompletionStatus(m_IOCPHandle, &m_NumberOfBytesTransferred, &m_CompletionKey, &m_lpOverlapped, m_Time);
	
	switch (m_LastWaitValue)
	{
	case 0:
		return IOCPWaitReturnType::RETURN_TIMEOUT;
	case 1:
		return IOCPWaitReturnType::RETURN_POST;
	default:
		break;
	}
	
	GameServerDebug::AssertDebugMsg("Wait Return Error");
	return IOCPWaitReturnType::RETURN_ERROR;
}

GameServerIOCP::GameServerIOCP(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time ,int _ThreadCount)
{
	Initialize(_Func, _Time, _ThreadCount);
}

GameServerIOCP::~GameServerIOCP()
{

}

GameServerIOCP::GameServerIOCP(GameServerIOCP&& _Other) noexcept
{

}


void GameServerIOCP::Initialize(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time, int _ThreadCount)
{
	if (_ThreadCount > 128)
	{
		GameServerDebug::AssertDebugMsg("Thread count is too much");
		return;
	}
	if (_ThreadCount <= 0)
	{
		SYSTEM_INFO SysInfo;
		GetSystemInfo(&SysInfo);
		_ThreadCount = SysInfo.dwNumberOfProcessors;
	}

	m_IOCPHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, _ThreadCount);

	for (int i = 0; i < _ThreadCount; i++)
	{
		AddThread(_Func, _Time);
	}
}

void GameServerIOCP::AddThread(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time)
{
	m_LockMutex.lock();
	std::shared_ptr<GameServerThreadWorker> Worker = std::make_shared<GameServerThreadWorker>(m_IOCPHandle, m_ThreadWorkerList.size(), _Time);
	m_ThreadWorkerList.push_back(Worker);
	m_ThreadList.push_back(std::make_shared<GameServerThread>(_Func, Worker));
	m_LockMutex.unlock(); 
}

void GameServerIOCP::Post(DWORD _DOWRDData, ULONG_PTR _ULONGPTRData)
{
	PostQueuedCompletionStatus(m_IOCPHandle, _DOWRDData, _ULONGPTRData, nullptr);
}

bool GameServerIOCP::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}