#include "PreCompile.h"
#include "GameServerObjectBase.h"


GameServerObjectBase::GameServerObjectBase()
	: m_Parent(nullptr)
{
	// initilize vector capacity
	m_LinkObjectList.reserve(10);
}

GameServerObjectBase::~GameServerObjectBase()
{

}

GameServerObjectBase::GameServerObjectBase(GameServerObjectBase&& _Other) noexcept
{

}

bool GameServerObjectBase::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}