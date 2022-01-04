#pragma once
#include <functional>
#include <mutex>
#include <thread>
#include <Windows.h>
/*
Usage		:  IOCP Manager 
Category	:  IOCP
Description :  IOCP의 일을 해주는 클래스
*/

enum class IOCPWaitReturnType
{
	RETURN_ERROR,
	RETURN_TIMEOUT,
	RETURN_POST,
};

class GameServerThreadWorker
{
	friend class GameServerIOCP;

public:
	GameServerThreadWorker(HANDLE _IOCPHandle, int _Index, DWORD _Time);

private:
	HANDLE m_IOCPHandle;
	DWORD m_NumberOfBytesTransferred;
	ULONG_PTR m_CompletionKey;
	LPOVERLAPPED m_lpOverlapped;
	DWORD m_Time;
	
	int m_Index;

	BOOL m_LastWaitValue;
	
public:
	int GetIndex()
	{
		return m_Index;
	}
	

public:
	template<class ConvertType>
	ConvertType ConvertCompletionKey()
	{
		return reinterpret_cast<ConvertType>(m_CompletionKey);
	}

public:
	IOCPWaitReturnType Wait();
};

class GameServerIOCP
{
public: //Default
	GameServerIOCP() {};
	GameServerIOCP(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time, int _ThreadCount);
	~GameServerIOCP();

	GameServerIOCP(const GameServerIOCP& _Other) = delete;
	GameServerIOCP(GameServerIOCP&& _Other)		noexcept;

protected:
	GameServerIOCP& operator=(const GameServerIOCP& _Other) = delete;
	GameServerIOCP& operator=(GameServerIOCP&& _Other)		= delete;

private: //Member Value
	HANDLE m_IOCPHandle;
	std::mutex m_LockMutex;

	std::vector<std::shared_ptr<class GameServerThread>> m_ThreadList;
	std::vector<std::shared_ptr<GameServerThreadWorker>> m_ThreadWorkerList;

public:
	void Initialize(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time, int _ThreadCount);

private:
	void AddThread(std::function<void(std::shared_ptr<GameServerThreadWorker>)> _Func, DWORD _Time);
	
public:
	void Post(DWORD _DOWRDData, ULONG_PTR _ULONGPTRData);
public:  //Member Function
	bool IsValid();
};

