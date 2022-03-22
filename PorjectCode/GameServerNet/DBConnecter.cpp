#include "PreCompile.h"
#include "DBConnecter.h"


DBConnecter::DBConnecter()
{

}

DBConnecter::~DBConnecter()
{

}

DBConnecter::DBConnecter(DBConnecter&& _Other) noexcept
{

}

bool DBConnecter::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}