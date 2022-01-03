#include "PreCompile.h"
#include <iostream>
#include "TestClass.h"
#include <GameServerBase/GameServerDebug.h>

int main()
{
	TestClass* testClass = nullptr;

	std::cout << "한글" << std::endl;
	

	if (!testClass->IsValid())
	{
		GameServerDebug::AssertDebugMsg("에러에러!");
		
	}
}