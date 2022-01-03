#include "PreCompile.h"
#include <iostream>
#include "TestClass.h"
#include <GameServerBase/GameServerDebug.h>

int main()
{
	TestClass* testClass = nullptr;

	std::cout << "Test" << std::endl;
	

	if (!testClass->IsValid())
	{
		GameServerDebug::AssertDebugMsg("TestError!");
		
	}
}