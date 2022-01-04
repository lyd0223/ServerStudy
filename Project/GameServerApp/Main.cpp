#include "PreCompile.h"
#include <iostream>
#include "TestClass.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerIOCP.h>
#include <conio.h>

void Func0(std::shared_ptr<GameServerThreadWorker> _Worker)
{
	while (1)
	{
		std::cout << "Func0 IOCP Thread Work" << std::endl;
	}
}

int main()
{
	/*
	TestClass* testClass = nullptr;

	std::cout << "Test" << std::endl;
	

	if (!testClass->IsValid())
	{
		GameServerDebug::AssertDebugMsg("TestError!");
		
	}
	*/
	GameServerIOCP IOCP0 = GameServerIOCP(Func0, 0, 10);

	while (true)
	{
		_getch();
	}
	

	
}