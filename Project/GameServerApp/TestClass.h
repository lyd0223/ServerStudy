#pragma once

/*
Usage		:  모든 클래스 기본.  
Category	:  Object 
Description :  오브젝트 상속용.
*/

class TestClass
{
public: //Default
	TestClass();
	~TestClass();

	TestClass(const TestClass& _Other) = delete;
	TestClass(TestClass&& _Other)		noexcept;

protected:
	TestClass& operator=(const TestClass& _Other) = delete;
	TestClass& operator=(TestClass&& _Other)		= delete;

private: //Member Value
	
	
public:  //Member Function
	bool IsValid();
};

