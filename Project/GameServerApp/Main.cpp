#include "PreCompile.h"
#include <iostream>
#include "TestClass.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerIOCP.h>
#include <conio.h>

GameServerIOCP IOCP0;
GameServerIOCP IOCP1;

void Func0(std::shared_ptr<GameServerThreadWorker> _Worker)
{
	while (1)
	{
		_Worker->Wait();
		const char* str = _Worker->ConvertCompletionKey<const char*>();
		
		std::cout << str << std::endl;
	}
}
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
			IOCP0.Post(0, reinterpret_cast<ULONG_PTR>(str));
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
	
	IOCP0.Initialize(Func0, INFINITE , 1);
	IOCP1.Initialize(Func1, 10, 10);


	while (true)
	{
		_getch();
	}
	

	
}