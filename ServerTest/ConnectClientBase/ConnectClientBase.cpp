#include <iostream>
#include <conio.h>

// 윈도우에서 소켓함수를 이용할때 쓰는 헤더
// Windows.h는 무조건 얘 아래잇어야.
#include <WinSock2.h>
#include <Windows.h>
// inet_pton 함수를 사용하기위한 헤더
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

	SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ConnectSocket == INVALID_SOCKET)
	{
		return 0;
	}

	std::cout << "Any key to connect" << std::endl;
	_getch();


	int Len = sizeof(SOCKADDR_IN);
	if (connect(ConnectSocket, (sockaddr*)&ServerAddr, Len) == SOCKET_ERROR)
	{
		return 0;
	}

	_getch();
}