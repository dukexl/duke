/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 16:56:27
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-02 14:04:33
 */
#ifndef _EPOLL_H_
#define _EPOLL_H_
#include <sys/epoll.h>
#include <vector>

class Channel;
class Epoll
{
private:
    int epfd;
    struct epoll_event *events;

public:
    Epoll();
    ~Epoll();

    void addFd(int fd, uint32_t op);
    void updateChannel(Channel *);
    void deleteChannel(Channel *);

    std::vector<Channel *> poll(int timeout = -1);
    // std::vector<epoll_event> poll(int timeout = -1);
};
#endif