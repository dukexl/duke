/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 16:51:38
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 14:53:57
 */
#include "include/InetAddress.h"
#include <string.h>

InetAddress::InetAddress() : addr_len(sizeof(addr))
{
    bzero(&addr, sizeof(addr));
}

InetAddress::InetAddress(const char *ip, u_int16_t port) : addr_len(sizeof(addr))
{
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    addr_len = sizeof(addr);
}

InetAddress::~InetAddress()
{
}

void InetAddress::setInetAddr(sockaddr_in _addr)
{
    addr = _addr;
}

sockaddr_in InetAddress::getAddr()
{
    return addr;
}

const char* InetAddress::getIp()
{
    return inet_ntoa(addr.sin_addr);
}

uint16_t InetAddress::getPort()
{
    return ntohs(addr.sin_port);
}