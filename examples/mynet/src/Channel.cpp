/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 09:26:40
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 17:10:31
 */
#include "include/Channel.h"
#include "include/EventLoop.h"
#include "include/Socket.h"
#include <unistd.h>
#include <sys/epoll.h>
#include <utility>

Channel::Channel(EventLoop *loop, int fd) : loop_(loop), fd_(fd), listen_events_(0), ready_events_(0), in_epoll_(false) // ,useThreadPool(true)
{
}

Channel::~Channel()
{
}

void Channel::handleEvent()
{
    if (ready_events_ & (EPOLLIN | EPOLLPRI))
    {
        read_callback_();
    }

    if (ready_events_ & (EPOLLOUT))
    {
        write_callback_();
    }
}

void Channel::enableReading()
{
    listen_events_ = EPOLLIN | EPOLLPRI;
    loop_->updateChannel(this);
}

void Channel::useET()
{
    listen_events_ |= EPOLLET;
    loop_->updateChannel(this);
}

int Channel::getFd()
{
    return fd_;
}

uint32_t Channel::getListenEvents()
{
    return listen_events_;
}

uint32_t Channel::getReadyEvents()
{
    return ready_events_;
}

void Channel::setInEpoll(bool in)
{
    in_epoll_ = in;
}

bool Channel::getInEpoll()
{
    return in_epoll_;
}

void Channel::setReadyEvents(uint32_t _events)
{
    ready_events_ = _events;
}

void Channel::setReadCallback(std::function<void()> const& callback)
{
    read_callback_ = callback;
}