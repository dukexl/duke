/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-07 14:53:40
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-07 14:55:23
 */
#include "../src/include/Connection.h"
#include "../src/include/Socket.h"
#include "../src/include/ThreadPool.h"

#include <unistd.h>
#include <cstring>
#include <functional>
#include <iostream>

void OneClient(int msgs, int wait)
{
    Socket *sock = new Socket();
    sock->connect("127.0.0.1", 8888);
    Connection *conn = new Connection(nullptr, sock);
    sleep(wait);
    int count = 0;
    while (count < msgs)
    {
        conn->setSendBuffer("I'm client!");
        conn->Write();
        if (conn->getState() == Connection::State::Closed)
        {
            conn->Close();
            break;
        }
        conn->Read();
        std::cout << "msg count " << count++ << ": " << conn->ReadBuffer() << std::endl;
    }
    delete conn;
}

int main(int argc, char *argv[])
{
    int threads = 100;
    int msgs = 100;
    int wait = 0;
    int o = -1;
    const char *optstring = "t:m:w:";
    while ((o = getopt(argc, argv, optstring)) != -1)
    {
        switch (o)
        {
        case 't':
            threads = std::stoi(optarg);
            break;
        case 'm':
            msgs = std::stoi(optarg);
            break;
        case 'w':
            wait = std::stoi(optarg);
            break;
        case '?':
            printf("error optopt: %c\n", optopt);
            printf("error opterr: %d\n", opterr);
            break;
        default:
            break;
        }
    }

    ThreadPool *poll = new ThreadPool(threads);
    std::function<void()> func = std::bind(OneClient, msgs, wait);
    for (int i = 0; i < threads; ++i)
    {
        poll->add(func);
    }
    delete poll;
    return 0;
}