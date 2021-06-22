#include <thread>
#include <iostream>
#include <mutex>

/* 1. 普通函数多线程调用*/
void f_thread()
{
    std::cout << "fthread" << std::endl;
}

// 2.有参函数
void fthread(int left, int right)
{
    std::cout << "left:" << left << " right:" << right;
}

// 3.在类内部创建线程（静态函数）
class CFThread
{
public:
    static void f_thread()
    {
        std::cout << "fthread" << std::endl;
    }

    static void start()
    {
        std::thread t1(f_thread);
        t1.join();
    }
};

// 4. 在singleton模式内部


int main()
{
    std::thread t1(f_thread);
    t1.join(); // 主线程等待子线程运行结束后才可执行下一步

    // 主线程
    std::cout << "main thread" << std::endl;
    getchar();
    return 0;
}