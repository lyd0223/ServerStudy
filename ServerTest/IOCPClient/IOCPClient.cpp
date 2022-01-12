#include <iostream>
#include <conio.h>
#include <thread>

#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")

std::thread RecvThread;
void RecvFunc(SOCKET _SessionSocket)
{
	while (1)
	{
		char Buffer[1024];
		recv(_SessionSocket, Buffer, sizeof(Buffer), 0);
		std::cout << _SessionSocket << " : " << Buffer << std::endl;
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

	if (inet_pton(AF_INET, "127.0.0.1", &ServerAddr.sin_addr) == SOCKET_ERROR)
	{
		return 0;

	}

	//								ip주소체계, TCP , TCP
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

	std::cout << "Connected!" << std::endl;

	RecvThread = std::thread(RecvFunc, ConnectSocket);
	while (1)
	{

		std::cout << "보낼 문자를 입력하세용 " << std::endl;
		std::string str;
		std::cin >> str;

		char Buffer[1024];
		memcpy_s(Buffer, sizeof(Buffer), str.c_str(), sizeof(str));

		send(ConnectSocket, Buffer, sizeof(Buffer), 0);
	}



	_getch();
}