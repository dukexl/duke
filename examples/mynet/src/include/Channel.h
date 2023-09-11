/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 09:16:05
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 15:17:13
 */
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "Macros.h"
#include <functional>
class Socket;
class EventLoop;
class Channel
{
private:
    EventLoop *loop_;
    int fd_;
    uint32_t listen_events_;
    uint32_t ready_events_;
    bool in_epoll_;
    std::function<void()> read_callback_;
    std::function<void()> write_callback_;

public:
    Channel(EventLoop *loop, int fd);
    ~Channel();

    DISALLOW_COPY_AND_MOVE(Channel);

    void handleEvent();
    void enableReading();

    int getFd();
    uint32_t getListenEvents();
    uint32_t getReadyEvents();
    bool getInEpoll();
    void setInEpoll(bool in = true);
    void useET();

    void setReadyEvents(uint32_t ev);
    void setReadCallback(std::function<void()> const &call);
};

#endif