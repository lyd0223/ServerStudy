#include <iostream>
#include <functional>

class TestClass
{
public:
    void mFunc()
    {
        std::cout << "mFunc\n" << std::endl;
    }
    void mFunc1(int _arg)
    {
        std::cout << "mFunc1 :" << _arg << std::endl << std::endl;
    }
};
void Func0()
{

    std::cout << "Func0\n" << std::endl;
}
void Func1(int _arg1 , int _arg2)
{
    std::cout << "Func1\n" << std::endl;
}
int main()
{
    {
        //함수포인터 기본 사용방법
        std::cout << "함수포인터 기본 사용" << std::endl;
        void (*funcPtr)();
        funcPtr = Func0;
        funcPtr();
    }

    {
        //인자가 여러개인 함수포인터
        std::cout << "인자가 여러개" << std::endl;
        void(*funcPtr)(int, int);
        funcPtr = Func1;
        funcPtr(1, 3);

    }

    {
        //멤버함수 함수포인터 사용방법
        std::cout << "멤버함수 함수 포인터 사용" << std::endl;
        void (TestClass::*funcPtr)();
        funcPtr = &TestClass::mFunc;
        TestClass testClass;
        (testClass.*funcPtr)();
    }

    {
        //std::function 사용방법
        std::cout << "std::function 사용" << std::endl;
        std::function<void()> EventFunc;
        EventFunc = std::bind(Func0);
        EventFunc();

        //멤버함수
        std::cout << "std::function 사용 멤버함수" << std::endl;
        TestClass testClass;
        EventFunc = std::bind(&TestClass::mFunc, &testClass);
        EventFunc();

        //인자가 있는 멤버함수
        std::cout << "std::function 사용 인자가 있는 멤버함수" << std::endl;
        EventFunc = std::bind(&TestClass::mFunc1, &testClass, 5);
        EventFunc();

        //이런식으로도 사용가능.
        std::function<void(int)> EventFunc2 = std::bind(&TestClass::mFunc1, &testClass, std::placeholders::_1);
        EventFunc2(1000);
        
        //클래스를 나중에 받을 수도 있음.
        std::function<void(TestClass&, int)> EventFunc3 = &TestClass::mFunc1;
        EventFunc3(testClass,555);
    }
}