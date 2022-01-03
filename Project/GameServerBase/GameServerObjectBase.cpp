#include "PreCompile.h"
#include "GameServerObjectBase.h"


GameServerObjectBase::GameServerObjectBase()
{

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