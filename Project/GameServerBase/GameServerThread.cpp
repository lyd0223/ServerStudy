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

bool GameServerThread::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}