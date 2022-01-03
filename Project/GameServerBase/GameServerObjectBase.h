#pragma once

/*
Usage		:  모든 클래스 기본.  
Category	:  Object 
Description :  오브젝트 상속용.
*/

class GameServerObjectBase
{
public: //Default
	GameServerObjectBase();
	~GameServerObjectBase();

	GameServerObjectBase(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase(GameServerObjectBase&& _Other)		noexcept;

protected:
	GameServerObjectBase& operator=(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase& operator=(GameServerObjectBase&& _Other)		= delete;

private: //Member Value
	
	
public:  //Member Function
	bool IsValid();
};

