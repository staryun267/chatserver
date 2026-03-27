#include "ChatServer.hpp"
#include "ChatService.hpp"

#include <signal.h>
#include <iostream>

//处理ctrl+c结束服务器后，重置user的状态信息
void resetHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}
int main(int argc,char* argv[])
{
    if(argc < 3)
    {
        cerr << "command invalid! example:./ChatServer 127.0.0.1 6000" << endl;
        exit(-1);
    }

    uint16_t port = atoi(argv[2]);
    char* ip = argv[1];
    signal(SIGINT,resetHandler);

    EventLoop loop;
    InetAddress listenaddr(ip,port);
    ChatServer server(&loop,listenaddr,"ChatServer");

    server.start();
    loop.loop();

    return 0;
}