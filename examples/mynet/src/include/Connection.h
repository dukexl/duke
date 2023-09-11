/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 16:58:35
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 16:47:39
 */
#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "Macros.h"
#include <functional>
#include <string>

class EventLoop;
class Socket;
class Channel;
class Buffer;
class Connection
{
public:
    enum State
    {
        Invalid = 1,
        Handshaking,
        Connected,
        Closed,
        Failed,
    };
    Connection(EventLoop *_loop, Socket *_sock);
    ~Connection();
    DISALLOW_COPY_AND_MOVE(Connection);

    void Read();
    void Write();

    void echo(int sockfd);
    void setDeleteConnectionCallback(std::function<void(Socket *)> const &callback);
    void setOnConnectCallback(std::function<void(Connection *)> const &callback);
    State getState();
    void Close();

    void setSendBuffer(const char *str);
    Buffer *getReadBuffer();
    const char *ReadBuffer();
    Buffer *getSendBuffer();
    const char *SendBuffer();
    void getLineSendBuffer();
    Socket *getSocket();

    void onConnect(std::function<void()> fn);

private:
    EventLoop *loop_;
    Socket *sock_;
    Channel *channel_;
    State state_;
    Buffer *read_buffer_;
    Buffer *send_buffer_;

    std::function<void(Socket *)> delete_connection_callback_;
    std::function<void(Connection *)> on_connect_callback_;

    void ReadNonBlocking();
    void WriteNonBlocking();
    void ReadBlocking();
    void WriteBlocking();
};

#endif