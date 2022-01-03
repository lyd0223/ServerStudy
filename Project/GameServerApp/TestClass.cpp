#include "PreCompile.h"
#include "TestClass.h"


TestClass::TestClass()
{

}

TestClass::~TestClass()
{

}

TestClass::TestClass(TestClass&& _Other) noexcept
{

}

bool TestClass::IsValid()
{
	if (this == nullptr)
	{
		return false;
	}
	return true;
}