/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 16:45:26
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 14:51:47
 */
#ifndef _INETADDRESS_H_
#define _INETADDRESS_H_
#include <arpa/inet.h>
#include "Macros.h"

class InetAddress
{
private:
    struct sockaddr_in addr;
    socklen_t addr_len;

public:
    InetAddress();
    InetAddress(const char *ip, uint16_t port);
    ~InetAddress();
    DISALLOW_COPY_AND_MOVE(InetAddress);

    void setInetAddr(sockaddr_in _addr);
    sockaddr_in getAddr();
    const char *getIp();
    uint16_t getPort();
};

#endif