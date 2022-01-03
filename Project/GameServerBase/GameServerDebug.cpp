#include "PreCompile.h"
#include "GameServerDebug.h"
#include <Windows.h>
#include <assert.h>


GameServerDebug::GameServerDebug()
{

}

GameServerDebug::~GameServerDebug()
{

}

GameServerDebug::GameServerDebug(GameServerDebug&& _Other) noexcept
{

}


void GameServerDebug::AssertDebug()
{
	assert(false);
}

void GameServerDebug::AssertDebugMsg(const std::string& _MsgStr)
{
	MessageBoxA(nullptr, _MsgStr.c_str(), "Warning!", MB_OK);
	assert(false);
}