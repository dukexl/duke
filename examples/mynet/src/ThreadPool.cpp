/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-01 15:09:31
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-07 09:30:53
 */
#include "include/ThreadPool.h"

ThreadPool::ThreadPool(int size) : stop(false)
{
    for (int i = 0; i < size; ++i)
    {
        // lamer表达式
        threads.emplace_back(std::thread([this]()
                                         {
            while(true)
            {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(tasks_mtx);
                    cv.wait(lock,[this](){return stop || !tasks.empty();  });
                    if(stop && tasks.empty())
                        return;
                    task = tasks.front();
                    tasks.pop();
                }
                task();
            } }));
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(tasks_mtx);
        stop = true;
    }
    cv.notify_all();
    for (std::thread &th : threads)
    {
        if (th.joinable())
            th.join();
    }
}