#pragma once
#include <string>
#include "GameServerIOCP.h"

/*
Usage		:  디버그용
Category	:  Debug
Description :  디버그 용도 클래스. 
			   로그띄워주는역할.
*/

enum class LogType
{
	LOGTYPE_ERROR,
	LOGTYPE_WARNING,
	LOGTYPE_INFO,
};
class GameServerDebug
{
private:
	class LogInfo
	{
	public:
		LogType m_Type;
		std::string m_Text;
	};
private: //Default
	GameServerDebug();
	virtual ~GameServerDebug() = 0;

	GameServerDebug(const GameServerDebug& _Other) = delete;
	GameServerDebug(GameServerDebug&& _Other)		noexcept;

protected:
	GameServerDebug& operator=(const GameServerDebug& _Other) = delete;
	GameServerDebug& operator=(GameServerDebug&& _Other)	  = delete;

private: //Member Value
	static GameServerIOCP m_IOCP;

public:
	static void Init();
	static void Destroy();

private:
	static void LogFunc(std::shared_ptr<GameServerThreadWorker> _Worker);

public:  //Member Function
	static void AssertDebug();
	static void AssertDebugMsg(const std::string& _Text);

	static void LogMsg(LogType _Type, const std::string& _Text);
	static void ErrorLogMsg(const std::string& _Text);
	static void WarningLogMsg(const std::string& _Text);
	static void InfoLogMsg(const std::string& _Text);

	static void PrintLastError();
	
};

