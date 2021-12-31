#include <iostream>
#include <thread>
#include <Windows.h>
#include <assert.h>
#include <conio.h>
#include <vector>
#include <functional>

HANDLE gIOCPHandle = 0;

void Func(int _index)
{
   
    DWORD Dword;
    ULONG_PTR CompletionKey;
    OVERLAPPED* Overlapped = nullptr;
    
    
    
    while (true)
    {
        GetQueuedCompletionStatus(gIOCPHandle, &Dword, &CompletionKey, &Overlapped, INFINITE);
        
        if (Dword == true)
        {
            std::cout << "End Thread : " << _index << std::endl;
            break;
        }

        std::cout << "Thread : " << _index << std::endl;
        if (CompletionKey != -1)
        {
           void(*ptr)() = reinterpret_cast<void(*)()>(CompletionKey);
           ptr();
        }
    }
    
}

void Event()
{
    std::cout << "Event! " << std::endl;
}

int main()
{
    //시스템 스레드 갯수.
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    
    int threadNum = sysinfo.dwNumberOfProcessors;

    //핸들 담아줌.
    gIOCPHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadNum);
    std::cout << gIOCPHandle << std::endl;
    
    if (!gIOCPHandle)
    {
        assert(false);
    }

    std::vector<std::thread*> ThreadVector;
    
    for (int i = 0; i < threadNum; i++)
    {
        std::thread* testThread = new std::thread(std::bind(Func,i));
        ThreadVector.push_back(testThread);
    }
    
    void(*EventPtr)() = Event;

    while (1)
    {
        char input = _getch();
        bool isQuit = 0;

        if (input == 'q') // q누르면 쓰레드 하나 종료.
        {
            isQuit = true;
            PostQueuedCompletionStatus(gIOCPHandle, isQuit, -1, nullptr);
        }
        else              // 쓰레드 하나 실행. Event함수를 실행시킴.
        {
            isQuit = false;
            PostQueuedCompletionStatus(gIOCPHandle, isQuit, reinterpret_cast<LONG_PTR>(EventPtr), nullptr);
        }
    }
    for (int i = 0; i < threadNum; i++)
    {
        ThreadVector[i]->join();
    }
    for (int i = 0; i < threadNum; i++)
    {
        delete(ThreadVector[i]);
    }

}
