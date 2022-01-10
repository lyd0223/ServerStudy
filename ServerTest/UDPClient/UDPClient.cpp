#include <iostream>
#include <conio.h>
#include <thread>

#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")


#include <iostream>

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

	if (inet_pton(AF_INET, "127.0.0.1", &ServerAddr.sin_addr) == SOCKET_ERROR)
	{
		return 0;

	}

	//								ip주소체계, TCP , TCP
	SOCKET ConnectSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (ConnectSocket == INVALID_SOCKET)
	{
		return 0;
	}

	while (1)
	{
		std::cout << "Enter Buffer plz" << std::endl;

		std::string str;
		std::cin >> str;

		char Buffer[10000] = {0,};
		memcpy(Buffer, str.c_str(), str.size());
		int  a = sizeof(Buffer);
		int b = sizeof(std::string);
		
		sendto(ConnectSocket, Buffer, sizeof(Buffer), 0, (struct sockaddr*)&ServerAddr, sizeof(SOCKADDR_IN));
	}
	

	closesocket(ConnectSocket);
	WSACleanup();
	
}