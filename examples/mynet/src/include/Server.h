/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 11:00:25
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 16:50:29
 */
#ifndef _SERVER_H_
#define _SERVER_H_
#include "Macros.h"
#include <map>
#include <vector>
#include <functional>

class EventLoop;
class Socket;
class Acceptor;
class Connection;
class ThreadPool;
class Server
{
private:
    EventLoop *mainReactor;
    Acceptor *acceptor;
    std::map<int,Connection*> connections;
    std::vector<EventLoop *> subReactors;
    ThreadPool *thpool;
    std::function<void(Connection*)> on_connect_callback_;

public:
    explicit Server(EventLoop *loop);
    ~Server();

    DISALLOW_COPY_AND_MOVE(Server);

    void newConnection(Socket *serv_sock);
    void deleteConnection(Socket *sock);
    void onConnect(std::function<void(Connection *)> fn);
};

#endif