#pragma once
#include <thread>
#include <Windows.h>

/*
Usage		:  내 프로젝트의 쓰레드
Category	:  Thread
Description :  std::thread를 감싼 프로젝트용 thread클래스.
*/

class GameServerThread
{
public: //Default
	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	explicit GameServerThread(_Fn&& _Fx, _Args&&... _Ax)
	{
		m_Thread = std::thread(_Fx, _Ax...);
	}

	GameServerThread();
	~GameServerThread();

	GameServerThread(const GameServerThread& _Other) = delete;
	GameServerThread(GameServerThread&& _Other)		noexcept;

protected:
	GameServerThread& operator=(const GameServerThread& _Other) = delete;
	GameServerThread& operator=(GameServerThread&& _Other)		= delete;

private: //Member Value
	std::thread m_Thread;
	
public:  //Member Function
	bool IsValid();
	void ThreadNameSetting(const wchar_t* _Name);
};

