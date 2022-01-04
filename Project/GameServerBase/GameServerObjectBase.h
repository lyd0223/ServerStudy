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
	GameServerObjectBase* m_Parent;
	std::vector<GameServerObjectBase*> m_LinkObjectList;

public:
	template<class ObjectType>
	ObjectType* GetParent()
	{
		return dynamic_cast<ObjectType*>(m_Parent);
	}
	template<class ObjectType>
	ObjectType* GetLinkObject(int _Index)
	{
		return dynamic_cast<ObjectType*>(m_LinkObjectList[_Index]);
	}
	void SetParent(GameServerObjectBase* _Object)
	{
		m_Parent = _Object;
	}
	void SetLinkObject(GameServerObjectBase* _Object)
	{
		m_LinkObjectList.push_back(_Object);
	}
	
public:  //Member Function
	bool IsValid();
};

