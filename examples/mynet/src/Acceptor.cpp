/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 16:33:04
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 14:43:05
 */
#include "include/Acceptor.h"
#include "include/Socket.h"
#include "include/InetAddress.h"
#include "include/Channel.h"
#include <utility>

Acceptor::Acceptor(EventLoop *loop) : loop_(loop),sock_(nullptr),channel_(nullptr),addr_(nullptr)
{
    sock_ = new Socket();
    addr_ = new InetAddress("127.0.0.1", 8888);
    sock_->bind(addr_);
    sock_->listen();
    // sock->setnonblocking(); 阻塞？？？  acceptor 使用阻塞式IO比较好
    channel_ = new Channel(loop_, sock_->getFd());
    std::function<void()> cb = std::bind(&Acceptor::acceptConnection, this);
    channel_->setReadCallback(cb);
    channel_->enableReading();
    // acceptChannel->setUseThreadPool(false);
}

Acceptor::~Acceptor()
{
    delete sock_;
    delete addr_;
    delete channel_;
}

void Acceptor::acceptConnection()
{
    InetAddress *clnt_addr = new InetAddress();
    Socket *clnt_sock = new Socket(sock_->accept(clnt_addr));
    clnt_sock->setnonblocking(); // 新接受到的连接设置为非阻塞式
    new_connection_callback_(clnt_sock);
    delete clnt_addr;
}

void Acceptor::setNewConnectionCallback(std::function<void(Socket *)> const &callback)
{
    new_connection_callback_ = callback;
}
