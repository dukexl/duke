/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-07 14:39:09
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-07 14:39:10
 */
#include "../src/include/Connection.h"
#include "../src/include/Socket.h"
#include <iostream>

int main()
{
    Socket *sock = new Socket();
    sock->connect("127.0.0.1", 8888);

    Connection *conn = new Connection(nullptr, sock);
    while (true)
    {
        conn->getLineSendBuffer();
        conn->Write();
        if (conn->getState() == Connection::State::Closed)
        {
            conn->Close();
            break;
        }
        conn->Read();
        std::cout << "Messge from server: " << conn->ReadBuffer() << std::endl;
    }
    delete conn;
    return 0;
}