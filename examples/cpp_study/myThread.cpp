#include <thread>
#include <iostream>
#include <mutex>

/* 普通函数多线程调用*/
void hello_thread()
{
    std::cout << "hello thread" << std::endl;
}

int main()
{
    std::thread t1(hello_thread);
    t1.join(); // 主线程等待子线程运行结束后才可执行下一步

    // 主线程
    std::cout << "main thread" << std::endl;
    getchar();
    return 0;
}