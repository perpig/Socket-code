// client.cpp
#include <iostream>
#include <cstring>     // 包含 memset
#include <cstdlib>     // 包含 exit
#include <sys/types.h> // 包含 socket
#include <sys/socket.h>
#include <netinet/in.h> // 包含 sockaddr_in，htonl 包含网络相关数据结构和常量的标准头文件
#include <unistd.h>     // 包含 close ，write等
#include <arpa/inet.h>  // 包含inet_ntoa 用于网络编程的头文件，主要用于处理互联网地址的转换和操作
using namespace std;

int main()
{
    while (true)
    {
        //------------------------------创建socket-------------------------------------
        // 函数原型int socket(int domain, int type, int protocol);
        // domain：通信域，type：指定套接字的类型 ，protocal:给定的通信域和套接字类型选择默认协议
        int sclient = socket(AF_INET, SOCK_STREAM, 0); // 创建
        if (-1 == sclient)
        {
            perror("socket error."); // 输出错误类型
            continue;
        }

        //------------------------------登陆服务器 创建连接------------------------------
        cout << "输入服务器ip:";
        string server_ip; // 用于临时存储输入的服务器ip
        cin >> server_ip;

        sockaddr_in server_addr;
        // 初始化服务器地址
        memset(&server_addr, 0x0, sizeof(server_addr));
        // 填充变量
        server_addr.sin_family = AF_INET;                           // 我们自己选的通信域
        server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str()); // ip地址
        server_addr.sin_port = htons(5555);                         // 端口号

        cout << "等待连接..." << endl;

        // 连接
        // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        if (connect(sclient, (sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        {
            printf("connect error !");
            close(sclient);
            continue;
        }
        else
        {
            cout << "连接成功." << endl;
        }

        // ---------------------------发送和接收---------------------------
        // 写入发送信息
        char send_data[255];
        cout << "键入发送信息:";
        cin >> send_data;

        // size_t bytes_written = write(sclient, send_data, strlen(send_data));
        // if (bytes_written < 0)
        // {
        //     perror("write error.");
        //     continue;
        // }

        // 发送信息
        if (send(sclient, send_data, strlen(send_data), 0) < 0)
        {
            perror("send error.");
            continue;
        }
        // 接收信息
        char revData[255];
        ssize_t ret = recv(sclient, revData, sizeof(revData), 0);
        if (ret < 0)
        {
            perror("recv error.");
            continue;
        }
        cout << "显示接收数据：" << endl;
        cout << revData << endl;

        close(sclient);
    }
    return 0;
}
