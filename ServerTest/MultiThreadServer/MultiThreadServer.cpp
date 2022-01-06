//³»²¨³»²¨!

#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>

#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")

std::mutex Mutex;
std::vector<SOCKET> SocketList;
std::vector<std::shared_ptr<std::thread>> ThreadList;

void RecvFunc(SOCKET _SessionSocket)
{
	while (1)
	{
		char Buffer[1024];
		int Result = recv(_SessionSocket, Buffer, sizeof(Buffer), 0);
		std::cout << _SessionSocket << " : " << Buffer << std::endl;
		
		Mutex.lock();
		for (int i = 0; i < SocketList.size(); i++)
		{
			if (SocketList[i] == _SessionSocket)
			{
				continue;
			}
			send(SocketList[i], Buffer, sizeof(Buffer), 0);
		}
		Mutex.unlock();
	}
}

int main()
{
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	SOCKADDR_IN ServerAddr = { 0, };

	ServerAddr.sin_family = AF_INET;

	ServerAddr.sin_port = htons(30001);

	if (inet_pton(AF_INET, "0.0.0.0", &ServerAddr.sin_addr) == SOCKET_ERROR)
	{
		return 0;

	}

	std::cout << "server start" << std::endl;

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ServerSocket == INVALID_SOCKET)
	{
		return 0;
	}

	if (bind(ServerSocket, (const sockaddr*)&ServerAddr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		return 0;
	}

	if (listen(ServerSocket, 512) == SOCKET_ERROR)
	{
		return 0;
	}

	SOCKADDR_IN UserAddr = { 0, };
	int Len = sizeof(SOCKADDR_IN);

	while (1)
	{
		SOCKET UserSocket = accept(ServerSocket, (sockaddr*)&UserAddr, &Len);
		if (UserSocket == INVALID_SOCKET)
		{
			std::cout << "¿¬°á ½ÇÆÐ" << std::endl;
			continue;
		}

		Mutex.lock();
		SocketList.push_back(UserSocket);
		ThreadList.push_back(std::make_shared<std::thread>(RecvFunc, UserSocket));
		Mutex.unlock();

		std::cout << "Someone connected" << std::endl;
	}
	

}