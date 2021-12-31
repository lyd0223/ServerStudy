#include <iostream>
#include <thread>

void Func0()
{
    std::cout << "Func0" << std::endl;
}

class TestClass
{
public:
    int a = 0;
    
    void Func()
    {
        
    }
};

void Func1(class TestClass _TestClass)
{
    std::cout << "Func1 " << _TestClass.a << std::endl;
}

int main()
{
    std::thread Thread1 = std::thread(Func0);
    
    Thread1.join();
}