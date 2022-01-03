#pragma once
#include <string>
/*
Usage		:  디버그용
Category	:  Debug
Description :  디버그 용도 클래스. 
			   로그띄워주는역할.
*/

class GameServerDebug
{
private: //Default
	GameServerDebug();
	virtual ~GameServerDebug() = 0;

	GameServerDebug(const GameServerDebug& _Other) = delete;
	GameServerDebug(GameServerDebug&& _Other)		noexcept;

protected:
	GameServerDebug& operator=(const GameServerDebug& _Other) = delete;
	GameServerDebug& operator=(GameServerDebug&& _Other)	  = delete;

private: //Member Value
	
	
public:  //Member Function
	static void AssertDebug();
	static void AssertDebugMsg(const std::string& _MsgStr);
};

