#include "PreCompile.h"
#include "GameServerNameObject.h"


GameServerNameObject::GameServerNameObject()
{

}

GameServerNameObject::~GameServerNameObject()
{

}

GameServerNameObject::GameServerNameObject(GameServerNameObject&& _Other) noexcept
{

}

bool GameServerNameObject::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}