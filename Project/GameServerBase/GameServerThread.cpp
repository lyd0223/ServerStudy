#include "PreCompile.h"
#include "GameServerThread.h"


GameServerThread::GameServerThread()
{

}

GameServerThread::~GameServerThread()
{

}

GameServerThread::GameServerThread(GameServerThread&& _Other) noexcept
{

}

void GameServerThread::Join()
{
	m_Thread.join();
}

void GameServerThread::ThreadNameSetting(const std::string& _Name)
{
	std::wstring wstr;
	wstr.assign(_Name.begin(), _Name.end());
	SetThreadDescription(GetCurrentThread(), wstr.c_str());
}

bool GameServerThread::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}