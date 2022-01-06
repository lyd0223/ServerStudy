//내꺼내꺼!

#include <iostream>
#include <conio.h>

// 윈도우에서 소켓함수를 이용할때 쓰는 헤더
// Windows.h는 무조건 얘 아래잇어야.
#include <WinSock2.h>
#include <Windows.h>
// inet_pton 함수를 사용하기위한 헤더
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")

int main()
{
	WSADATA wsa;
	
	// 윈도우에서 우리 프로그램이 소켓통신을 하겟다고 미리 알려주는 함수
	// MAKEWORD(2,2) : 소켓통신방식 버전
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	// 소켓통신을 위한 주소정보를 담는 구조체.
	SOCKADDR_IN ServerAddr = { 0, };

	// IPv4를 이용하겠다.
	ServerAddr.sin_family = AF_INET;
	
	// ip주소로 내컴퓨터까지는 올 수 있지만,
	// 내 컴퓨터에서 어떤 포트로 갈지는 모르기때문에 포트번호를지정.
	// cmd에서 netstat -n을 입력하면 
	// netstat -an | grep 30001을 입력하면 사용하는 포트인지 확인가능
	ServerAddr.sin_port = htons(30001);

	// 주소값을 os가 사용하는 엔디언값에 맞춰준다.
	if (inet_pton(AF_INET, "0.0.0.0", &ServerAddr.sin_addr) == SOCKET_ERROR)
	{
		return 0;

	}
	
	std::cout << "server start" << std::endl;
	
	//소켓 생성

	//SOCKET_STREAM 연결지속을 하겠다는 옵션.
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
	//접속을 기다린다.
    SOCKET UserSocket =	accept(ServerSocket,(sockaddr*)&UserAddr, &Len);
	if (UserSocket == INVALID_SOCKET)
	{
		return 0;
	}
	std::cout << "Someone connected" << std::endl;

	_getch();
	
}