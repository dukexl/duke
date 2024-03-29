/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-30 17:04:27
 * @LastEditors: xuli
 * @LastEditTime: 2023-05-31 10:33:15
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <vector>
#include "util.h"
#include "Epoll.h"
#include "InetAddress.h"
#include "Socket.h"
#include "Channel.h"

#define READ_BUFFER 1024

void handleReadEvent(int sockfd){
    char buf[READ_BUFFER];
    while(true){    //由于使用非阻塞IO，读取客户端buffer，一次读取buf大小数据，直到全部读取完毕
        bzero(&buf, sizeof(buf));
        ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
        if(bytes_read > 0){
            printf("message from client fd %d: %s\n", sockfd, buf);
            write(sockfd, buf, sizeof(buf));
        } else if(bytes_read == -1 && errno == EINTR){  //客户端正常中断、继续读取
            printf("continue reading");
            continue;
        } else if(bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){//非阻塞IO，这个条件表示数据全部读取完毕
            printf("finish reading once, errno: %d\n", errno);
            break;
        } else if(bytes_read == 0){  //EOF，客户端断开连接
            printf("EOF, client fd %d disconnected\n", sockfd);
            close(sockfd);   //关闭socket会自动将文件描述符从epoll树上移除
            break;
        }
    }
}

int main()
{
    Socket *serv_sock = new Socket();
    InetAddress *serv_addr = new InetAddress("127.0.0.1",8888);
    serv_sock->bind(serv_addr);
    serv_sock->listen();
    serv_sock->setnonblocking();

    Epoll *ep = new Epoll();
    Channel *servChannel = new Channel(ep,serv_sock->getFd());
    servChannel->enableReading();

    // ep->addFd(serv_sock->getFd(),EPOLLIN|EPOLLET);
    while(true)
    {
        std::vector<Channel*> events = ep->poll();        
        int nfds = events.size();

        for(int i = 0; i < nfds; ++i)
        {
            int chfd = events[i]->getFd();

            if(chfd == serv_sock->getFd())
            {        //新客户端连接
                InetAddress *clnt_addr = new InetAddress();      //会发生内存泄露！没有delete
                Socket *clnt_sock = new Socket(serv_sock->accept(clnt_addr));       //会发生内存泄露！没有delete
                printf("new client fd %d! IP: %s Port: %d\n", clnt_sock->getFd(), inet_ntoa(clnt_addr->addr.sin_addr), ntohs(clnt_addr->addr.sin_port));
                clnt_sock->setnonblocking();
                Channel *clntChannel = new Channel(ep, clnt_sock->getFd());
                clntChannel->enableReading();
            } 
            else if(events[i]->getEvents() & EPOLLIN)
            {      //可读事件
                handleReadEvent(events[i]->getFd());
            } 
            else
            {         //其他事件，之后的版本实现
                printf("something else happened\n");
            }
        }

    }

    delete serv_sock;
    delete serv_addr;
    return 0;

}