#pragma once

/*
Usage		:  이름달린 오브젝트 상속용.  
Category	:  Object 
Description :  오브젝트 상속용.
*/

class GameServerNameObject
{
public: //Default
	GameServerNameObject();
	~GameServerNameObject();

	GameServerNameObject(const GameServerNameObject& _Other) = delete;
	GameServerNameObject(GameServerNameObject&& _Other)		noexcept;

protected:
	GameServerNameObject& operator=(const GameServerNameObject& _Other) = delete;
	GameServerNameObject& operator=(GameServerNameObject&& _Other)		= delete;

protected:
	std::string m_Name;

public:
	void SetName(const std::string& _Name)
	{
		m_Name = _Name;
	}
	std::string GetName()
	{
		return m_Name;
	}
	const char* GetNamePtr()
	{
		return m_Name.c_str();
	}

private: //Member Value
	
	
public:  //Member Function
	bool IsValid();
};

