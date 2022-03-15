#include "PreCompile.h"
#include "DBManager.h"


DBManager::DBManager()
{

}

DBManager::~DBManager()
{

}

DBManager::DBManager(DBManager&& _Other) noexcept
{

}

bool DBManager::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}