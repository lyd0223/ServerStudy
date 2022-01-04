#include "PreCompile.h"
#include <iostream>
#include "TestClass.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerIOCP.h>
#include <conio.h>

GameServerIOCP IOCP0;
GameServerIOCP IOCP1;

void Func1(std::shared_ptr<GameServerThreadWorker> _Worker)
{
	while (1)
	{
		switch (_Worker->Wait())
		{
		case IOCPWaitReturnType::RETURN_ERROR:
			break;
		case IOCPWaitReturnType::RETURN_TIMEOUT:
		{
			const char* str = "Test String";
			GameServerDebug::ErrorLogMsg(str);
			
			break;
		}
		case IOCPWaitReturnType::RETURN_POST:
			break;
		default:
			break;
		}	
	}
}

int main()
{
	
	GameServerDebug::Init();

	IOCP1.Init(Func1, 10, 10);



	while (true)
	{
		_getch();
	}
	

	
}