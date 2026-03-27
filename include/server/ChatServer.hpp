#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

class ChatServer
{
public:
    //初始化聊天服务器
    ChatServer(
            EventLoop* loop,
            const InetAddress& listenaddr,
            const string& namearg
    );

    //启动服务
    void start();
private:
    TcpServer server_;
    EventLoop *loop_;

    //上报链接相关信息的回调函数
    void onConnection(const TcpConnectionPtr&);

    //上报读写事件相关的回调函数
    void onMessage(
            const TcpConnectionPtr&,
            Buffer*,
            Timestamp
    );
};


#endif