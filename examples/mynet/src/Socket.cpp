/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 16:40:09
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-06 15:09:10
 */
#include "include/Socket.h"
#include "include/util.h"
#include "include/InetAddress.h"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

Socket::Socket() : fd(-1)
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    errif(fd == -1, "socket create error");
}

Socket::Socket(int _fd) : fd(_fd)
{
    errif(fd == -1, "socket create error");
}

Socket::~Socket()
{
    if (fd == -1)
    {
        close(fd);
        fd = -1;
    }
}

void Socket::bind(InetAddress *_addr)
{
    struct sockaddr_in addr = _addr->getAddr();
    errif(::bind(fd, (sockaddr *)&addr, sizeof(addr)) == -1, "socket bind error");
}

void Socket::listen()
{
    errif(::listen(fd, SOMAXCONN) == -1, "socket listen error");
}

int Socket::accept(InetAddress *_addr)
{
    int clnt_sockfd = -1;
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    socklen_t addr_len = sizeof(addr);

    if (isNonBlocking())
    {
        while (true)
        {
            clnt_sockfd = ::accept(fd, (sockaddr *)&addr, &addr_len);
            if (clnt_sockfd == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK)))
            {
                continue;
            }

            if (clnt_sockfd == -1)
            {
                errif(true, "socket accept error!");
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        clnt_sockfd = ::accept(fd, (sockaddr *)&addr, &addr_len);
        errif(clnt_sockfd == -1, "socket accept error");
    }

    _addr->setInetAddr(addr);
    return clnt_sockfd;
}

void Socket::connect(InetAddress *_addr)
{
    struct sockaddr_in addr = _addr->getAddr();

    if (fcntl(fd, F_GETFL) & O_NONBLOCK)
    {
        while (true)
        {
            int ret = ::connect(fd, (sockaddr *)&addr, sizeof(addr));
            if (ret == 0)
                break;

            if (ret == -1 && errno == EINPROGRESS)
                continue;

            if (ret == -1)
                errif(true, "Socket connect error");
        }
    }
    else
    {
        errif(::connect(fd, (sockaddr *)&addr, sizeof(addr)) == -1, "socket connect error");
    }
}

void Socket::connect(const char *ip, uint16_t port)
{
    InetAddress *addr = new InetAddress(ip, port);
    connect(addr);
    delete addr;
}

void Socket::setNonBlocking()
{
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
}

bool Socket::isNonBlocking()
{
    return (fcntl(fd, F_GETFL) & O_NONBLOCK) != 0;
}

int Socket::getFd()
{
    return fd;
}
