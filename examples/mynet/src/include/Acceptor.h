/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 16:11:46
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 14:43:42
 */
#ifndef _ACCEPTOR_H_
#define _ACCEPTOR_H_

#include "Macros.h"
#include <functional>
class EventLoop;
class Socket;
class InetAddress;
class Channel;
class Acceptor
{
public:
    explicit Acceptor(EventLoop *loop);
    ~Acceptor();

    DISALLOW_COPY_AND_MOVE(Acceptor);
    
    void acceptConnection();
    void setNewConnectionCallback(std::function<void(Socket *)> const &);

private:
    EventLoop *loop_;
    Socket *sock_;
    InetAddress *addr_;
    Channel *channel_;
    std::function<void(Socket *)> new_connection_callback_;
};

#endif