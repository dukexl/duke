/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 11:12:59
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 16:55:47
 */
#include "include/Server.h"
#include "include/Socket.h"
#include "include/InetAddress.h"
#include "include/Channel.h"
#include "include/Acceptor.h"
#include "include/Connection.h"
#include "include/ThreadPool.h"
#include "include/EventLoop.h"
#include <functional>
#include <string.h>
#include <unistd.h>

#define READ_BUFFER 1024

Server::Server(EventLoop *_loop) : mainReactor(_loop), acceptor(nullptr), thpool(nullptr)
{
    acceptor = new Acceptor(mainReactor);

    std::function<void(Socket *)> cb = std::bind(&Server::newConnection, this, std::placeholders::_1);
    acceptor->setNewConnectionCallback(cb);

    int size = std::thread::hardware_concurrency();
    thpool = new ThreadPool(size);
    for (int i = 0; i < size; ++i)
    {
        subReactors.push_back(new EventLoop()); // 多个事件
    }

    for (int i = 0; i < size; ++i)
    {
        std::function<void()> sub_loop = std::bind(&EventLoop::loop, subReactors[i]);
        thpool->add(sub_loop);
    }
}

Server::~Server()
{
    delete acceptor;
    delete thpool;
}

void Server::newConnection(Socket *serv_sock)
{
    uint64_t random = serv_sock->getFd() % subReactors.size();
    Connection *conn = new Connection(subReactors[random], serv_sock);
    std::function<void(Socket *)> cb = std::bind(&Server::deleteConnection, this, std::placeholders::_1);
    conn->setDeleteConnectionCallback(cb);
    conn->setOnConnectCallback(on_connect_callback_);
    connections[serv_sock->getFd()] = conn;
}

void Server::deleteConnection(Socket *sock)
{
    int sockfd = sock->getFd();
    auto it = connections.find(sockfd);
    if (it != connections.end())
    {
        Connection *conn = connections[sockfd];
        connections.erase(sockfd);
        delete conn;
        conn = nullptr;
    }
}

void Server::onConnect(std::function<void(Connection *)> fn)
{
    on_connect_callback_ = std::move(fn);
}