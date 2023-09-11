/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 10:50:43
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 16:47:22
 */
#ifndef _EVENTLOOP_H_
#define _EVENTLOOP_H_
#include <functional>
#include "Macros.h"

class Epoll;
class Channel;
class ThreadPool;
class EventLoop
{
private:
    Epoll *ep;
    bool quit;

public:
    EventLoop();
    ~EventLoop();

    DISALLOW_COPY_AND_MOVE(EventLoop);

    void loop();
    void updateChannel(Channel *);
};

#endif