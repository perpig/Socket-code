// server 服务器
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
    //------------------------------创建socket-------------------------------------
    // 函数原型int socket(int domain, int type, int protocol);
    // domain：通信域，type：指定套接字的类型 ，protocal:给定的通信域和套接字类型选择默认协议
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0); // 创建
    if (-1 == socket_fd)
    {
        perror("socket error."); // 输出错误类型
        exit(-1);
    }

    //-----------------------------绑定socket和端口号--------------------------------
    // struct sockaddr
    // {
    //      sa_family_t sa_family;  /* 地址族 (Address Family)*/
    //      char sa_data[14];        /* 地址数据 (Address Data)*/
    // };
    //
    // struct sockaddr_in
    // {
    //     sa_family_t sin_family;  /* 协议族 */
    //     in_port_t sin_port;      /* 端口号 */
    //     struct in_addr sin_addr; /* IP 地址 */
    //     unsigned char sin_zero[8];
    // };

    struct sockaddr_in socket_addr;
    memset(&socket_addr, 0x0, sizeof(socket_addr)); // 清零

    // 填充变量
    socket_addr.sin_family = AF_INET;                // 我们自己选的通信域
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 端口号 INADDR_ANY代表任意地址（通常为 0.0.0.0），用于让服务器监听所有可用的网络接口
    socket_addr.sin_port = htons(5555);              // ip地址
    // 将地址与套接字进行关联、绑定
    // 函数原型int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if (bind(socket_fd, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) == -1)
    {
        perror("bind error.");
        exit(-1);
    }

    // ---------------------------------监听该端口号--------------------------------------
    // int listen(int sockfd, int backlog);         // backlog 用来描述 sockfd 的等待连接队列能够达到的最大值
    if (listen(socket_fd, 5) == -1)
    {
        perror("listen error.");
        exit(-1);
    }

    int client; // 客户端
    sockaddr_in client_addr;
    int client_addrlen = sizeof(client_addr);
    char revData[255];
    // 循环接受数据
    // 持续监听连接：通过循环，服务器能够持续监听和接受来自客户端的连接请求。当有多个客户端同时尝试连接时，循环能够确保每个连接都被接受并处理。
    // 处理多个客户端：每次接受到一个新的连接后，服务器可以处理与该客户端的通信，而不需要关闭服务器或结束程序。这样可以实现并发处理。
    // 数据交换：在接收到客户端连接后，服务器能够处理数据接收和发送。循环确保这一过程可以重复进行，直到服务器被显式关闭。
    while (true)
    {
        //---------------------------------接受来自客户端的连接请求------------------------------
        // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        // 参数 addr 是一个传出参数，参数 addr 用来返回已连接的客户端的 IP 地址与端口号等这些信息。
        cout << "本服务器ip:" << inet_ntoa(socket_addr.sin_addr) << endl;
        cout << "等待连接...\n";
        client = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addrlen);
        if (client == -1)
        {
            perror("accept error.");
            continue; // 循环接受数据的错误处理，可以让程序继续监听下一个连接，而不是直接退出
        }
        // inet_ntoa() 将一个网络字节顺序表示的 IP 地址转换为点分十进制的字符串表示形式（例如，"192.168.1.1"）。
        cout << "接受到一个连接" << inet_ntoa(client_addr.sin_addr) << endl;

        //---------------------------------接收数据 从socket中读取字符------------------------------
        // ssize_t recv(int sockfd, void *buf, size_t len, int flags);      返回值是接受到的字节数
        // 参数 buf 指向了一个数据接收缓冲区，参数 len 指定了读取数据的字节大小，参数 flags 可以指定一些标志用于控制如何接收数据。
        ssize_t ret = recv(client, revData, sizeof(revData), 0);
        if (ret < 0)
        {
            perror("recv error.");
            continue; // 循环
        }
        cout << "显示接收数据：" << endl;
        cout << revData << endl;

        //---------------------------------发送数据给对方（响应）------------------------------
        // 写入信息
        char sentData[255];
        cout << "键入发送信息:";
        cin >> sentData;

        // ssize_t bytes_written = write(client, sentData, strlen(sentData));
        // if (bytes_written < 0)
        // {
        //     perror("write error.");
        //     continue;
        // }

        // 发送信息
        // ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        if (send(client, sentData, strlen(sentData), 0) < 0)
        // 选择发送时应该是实际的长度 所以用strlen()
        // 即使这里显示成功 也不代表对面就接收成功
        {
            perror("send error.");
            continue;
        }

        close(client); // 关闭套接字
    }

    return 0;
}
