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

void GameServerThread::ThreadNameSetting(const wchar_t* _Name)
{
	SetThreadDescription(GetCurrentThread(), _Name);
}

bool GameServerThread::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}