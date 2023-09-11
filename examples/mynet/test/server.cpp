/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-05-31 11:13:40
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-01 14:36:57
 */
#include "src/EventLoop.h"
#include "src/Server.h"

int main() {
    // new一个epoll 对象，一个fd 一个事件数组
    EventLoop *loop = new EventLoop();

    Server *server = new Server(loop);
    loop->loop();
    delete server;
    delete loop;
    
    return 0;
}