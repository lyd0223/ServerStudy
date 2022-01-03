#pragma once

/*
Usage		:  테스트 클래스
Category	:  Object 
Description :  테스트용 클래스.
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

