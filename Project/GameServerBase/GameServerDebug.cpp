#include "PreCompile.h"
#include "GameServerDebug.h"
#include <Windows.h>
#include <assert.h>
#include <iostream>


GameServerIOCP GameServerDebug::m_IOCP;

GameServerDebug::GameServerDebug()
{

}

GameServerDebug::~GameServerDebug()
{

}

GameServerDebug::GameServerDebug(GameServerDebug&& _Other) noexcept
{

}

void GameServerDebug::LogFunc(std::shared_ptr<GameServerThreadWorker> _Worker)
{
	while (true)
	{
		_Worker->Wait();

		if (_Worker->GetNumberOfBytesTransferred() == -1)
		{
			return;
		}

		std::unique_ptr<LogInfo> Info = std::unique_ptr<LogInfo>(_Worker->GetConvertCompletionKey<LogInfo*>());
	
		std::string TypeText = "";
		switch (Info->m_Type)
		{
		case LogType::LOGTYPE_ERROR:
			TypeText = "ERROR : ";
			break;
		case LogType::LOGTYPE_WARNING:
			TypeText = "WARNING : ";
			break;
		case LogType::LOGTYPE_INFO:
			TypeText = "INFO : ";
			break;
		default:
			break;
		}

		std::cout << TypeText << Info->m_Text << std::endl;
	}
}

void GameServerDebug::Init()
{
	m_IOCP.Init(&LogFunc, INFINITE, 1);
}

void GameServerDebug::Destroy()
{

}

void GameServerDebug::AssertDebug()
{
	assert(false);
}

void GameServerDebug::AssertDebugMsg(const std::string& _Text)
{
	MessageBoxA(nullptr, _Text.c_str(), "Warning!", MB_OK);
	assert(false);
}


void GameServerDebug::LogMsg(LogType _Type, const std::string& _Text)
{
	std::unique_ptr<LogInfo> Info = std::make_unique<LogInfo>();
	Info->m_Type = _Type;
	Info->m_Text = _Text;

	m_IOCP.Post(0, reinterpret_cast<ULONG_PTR>(Info.get()));

	Info.release();
}
void GameServerDebug::ErrorLogMsg(const std::string& _Text)
{
	LogMsg(LogType::LOGTYPE_ERROR, _Text);
}
void GameServerDebug::WarningLogMsg(const std::string& _Text)
{
	LogMsg(LogType::LOGTYPE_WARNING, _Text);
}
void GameServerDebug::InfoLogMsg(const std::string& _Text)
{
	LogMsg(LogType::LOGTYPE_INFO, _Text);
}


void GameServerDebug::PrintLastError()
{
	DWORD ErrorCode = GetLastError();
	
	char* msg = nullptr;
	FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		nullptr,
		ErrorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		msg,
		0,
		nullptr);
	if (msg != nullptr)
	{
		printf_s("ErrorCode : %d \nErrorMsg : %s", ErrorCode, msg);
		LocalFree(msg);
	}


}