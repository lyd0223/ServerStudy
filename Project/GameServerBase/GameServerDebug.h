#pragma once
#include <string>
/*
Usage		:  모든 클래스 기본.  
Category	:  Object 
Description :  오브젝트 상속용.
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

