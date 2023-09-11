/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 16:37:16
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 14:55:50
 */
#ifndef _SOCKET_H_
#define _SOCKET_H_
#include "Macros.h"

class InetAddress;
class Socket
{
private:
    int fd;

public:
    Socket();
    explicit Socket(int);
    ~Socket();

    DISALLOW_COPY_AND_MOVE(Socket);

    void bind(InetAddress *addr);
    void listen();
    int accept(InetAddress *addr);
    void connect(InetAddress *addr);
    void connect(const char *ip,uint16_t port);
    
    void setNonBlocking();   
    bool isNonBlocking();
    int getFd();
};

#endif