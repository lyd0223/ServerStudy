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

	//								ip주소체계, TCP , TCP
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (ServerSocket == INVALID_SOCKET)
	{
		return 0;
	}

	if (bind(ServerSocket, (const sockaddr*)&ServerAddr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		return 0;
	}

	std::cout << "Server is open" << std::endl;

	while (true)
	{
		SOCKADDR_IN RecvAdd = { 0, };
		int RecvAddSize = sizeof(SOCKADDR_IN);
		char RecvBuffer[10000];

		int result = recvfrom(ServerSocket, RecvBuffer, sizeof(RecvBuffer), 0, (struct sockaddr*)&RecvAdd, &RecvAddSize);

		if (result < 0)
			return 0;
		std::cout << RecvBuffer << std::endl;
	}

	

}
