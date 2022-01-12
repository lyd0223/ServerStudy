
#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <assert.h>

#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")

struct Data
{
public:
	SOCKET Sokcet;
	WSABUF Buffers;
	DWORD BufferCount;
	DWORD NumberOfBytesRecvd;
	DWORD Flags;
	WSAOVERLAPPED Overlapped;
	
	char Buffer[1024];

public:
	Data()
	{
		memset(this, 0, sizeof(Data));
		
		Buffers.buf = Buffer;
		Buffers.len = sizeof(Buffer);
	}
};

HANDLE gIOCPHandle;
std::vector<std::shared_ptr<std::thread>> ThreadVector;

void RecvFunc()
{
	while (1)
	{
		DWORD NumberofBytes;
		ULONG_PTR Key;
		LPOVERLAPPED OverLapped;
		GetQueuedCompletionStatus(gIOCPHandle, &NumberofBytes, &Key, &OverLapped, INFINITE);
		
		Data* data = reinterpret_cast<Data*>(Key);
		
		std::cout << data->Buffer << std::endl;
		if (WSARecv(data->Sokcet, &data->Buffers, 1, &data->NumberOfBytesRecvd, &data->Flags, &data->Overlapped, nullptr) == SOCKET_ERROR)
		{
			int ErrorCode = GetLastError();
			if (ErrorCode != WSA_IO_PENDING)
			{
				return;
			}
		}
	}
}

int main()
{
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	//IOCP핸들만들기.
	gIOCPHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 5);

	// 쓰레드만들기.
	for (int i = 0; i < 5; i++)
		ThreadVector.push_back(std::make_shared<std::thread>(RecvFunc));

	//SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKET ServerSocket = WSASocket(AF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
	if (ServerSocket == INVALID_SOCKET)
		return 0;
	
	//소켓옵션 바꿔주기.
	//Mode = 1 NonBlocking Mode
	//Mode = 0 Blocking Mode
	unsigned long Mode = 1;
	int Result = ioctlsocket(ServerSocket, FIONBIO, &Mode);
	if (Result == SOCKET_ERROR)
	{
		DWORD ErrorCode = GetLastError();
		assert(false);
		return 0;
	}

	//서버 바인드
	SOCKADDR_IN ServerAddr = { 0, };

	ServerAddr.sin_family = AF_INET;

	ServerAddr.sin_port = htons(30001);

	if (inet_pton(AF_INET, "0.0.0.0", &ServerAddr.sin_addr) == SOCKET_ERROR)
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

	std::cout << "Server Start" << std::endl;
	
	while (1)
	{
		SOCKADDR_IN UserAddr = { 0, };
		UserAddr.sin_family = AF_INET;
		int Len = sizeof(SOCKADDR_IN);

		SOCKET UserSocket = accept(ServerSocket, (sockaddr*)&UserAddr, &Len);
		if (UserSocket == INVALID_SOCKET)
		{
			int ErrorCode = WSAGetLastError();
			
			if (ErrorCode == WSAEWOULDBLOCK)
			{
				Sleep(1);
				continue;
			}

			std::cout << "연결 실패" << std::endl;
			continue;
		}
		std::cout << "Someone connected" << std::endl;
		
		
		Data* data = new Data();
		data->Sokcet = UserSocket;
		//IOCP 생성하는거랑은 좀 다른의미로 쓰인다.
		CreateIoCompletionPort((HANDLE)UserSocket, gIOCPHandle, reinterpret_cast<ULONG_PTR>(data), 0);
		
		if (WSARecv(UserSocket, &data->Buffers, 1, &data->NumberOfBytesRecvd, &data->Flags, &data->Overlapped, nullptr) == SOCKET_ERROR)
		{
			int ErrorCode = GetLastError();
			if (ErrorCode != WSA_IO_PENDING)
			{
				assert(false);
			}
		}
		

	}
	
	WSACleanup();

}