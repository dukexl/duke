/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 11:02:13
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-02 17:08:38
 */
#include "EventLoop.h"
#include "Epoll.h"
#include "Channel.h"
#include "ThreadPool.h"
#include <vector>

EventLoop::EventLoop() : ep(nullptr),  quit(false) // threadPool(nullptr),
{
    ep = new Epoll();
    // threadPool = new ThreadPool();
}

EventLoop::~EventLoop()
{
    delete ep;
}

void EventLoop::loop()
{
    while (!quit)
    {
        std::vector<Channel *> chs;
        chs = ep->poll();
        // 打印一下日志看一下是否会阻塞
        // printf("test\n");
        for (auto it = chs.begin(); it != chs.end(); it++)
        {
            (*it)->handleEvent();
        }
    }
}

void EventLoop::updateChannel(Channel *ch)
{
    ep->updateChannel(ch);
}

// void EventLoop::addThread(std::function<void()> func)
// {
//     threadPool->add(func);
// }