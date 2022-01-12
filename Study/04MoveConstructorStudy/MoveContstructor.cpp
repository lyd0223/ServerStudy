#include <iostream>

class TestClass
{
public:
	int a;
public:
	TestClass()
	{
		a = 0;
		std::cout << "Constructor" << std::endl;
	}
	TestClass(int num)
	{
		a = num;
		std::cout << "Constructor2" << std::endl;
	}
	TestClass(const TestClass& _TestClass)
	{
		std::cout << "Copy Constructor" << std::endl;
		a = _TestClass.a;
	}
	TestClass(TestClass&& _TestClass) noexcept
	{
		std::cout << "Move Constructor" << std::endl;
		a = _TestClass.a;
	}
	//TestClass& operator= (const TestClass& _TestClass) = default;
	TestClass& operator= (TestClass&& _TestClass) noexcept
	{
		std::cout << "RvalueRef operator=" << std::endl;
		return _TestClass;
	}
	TestClass operator+ (TestClass& _TestClass) noexcept
	{
		std::cout << "Revalueref operator+" << std::endl;
		TestClass resultTestClass;
		resultTestClass.a = this->a + _TestClass.a;
		return resultTestClass;
	}
};
int main()
{
	{
		TestClass* tc = new TestClass();
		TestClass* tc1 = new TestClass(5);
		TestClass* tc2 = new TestClass(*tc1);
		TestClass* tc3 = std::move(tc1);
	}
	std::cout << std::endl;
	{
		TestClass tc = TestClass(2);
		TestClass tc_copy(tc);
		TestClass tc_move(std::move(tc));
		TestClass tc2 = tc;
		std::cout << std::endl;
		TestClass tc3;
		TestClass tc_oper = tc + tc;
		
	}
}