// server_pthread.cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <mutex>

using namespace std;

std::mutex io_mutex; // 用来保护标准输入输出

void *handle_client(void *client_socket)
{
    int client = *(int *)client_socket;
    delete (int *)client_socket; // 提前释放指针，避免重复释放
    char revData[255];

    while (true)
    {
        ssize_t ret = recv(client, revData, sizeof(revData), 0);
        if (ret <= 0)
        {
            perror("recv error or client disconnected.");
            break;
        }

        // 锁定输出以避免多个线程同时输出
        {
            std::lock_guard<std::mutex> lock(io_mutex);
            cout << "显示接收数据：" << revData << endl;
        }

        // 发送回应
        char sentData[255];
        {
            std::lock_guard<std::mutex> lock(io_mutex);
            cout << "键入发送信息: ";
            cin >> sentData;
        }

        if (send(client, sentData, strlen(sentData), 0) < 0)
        {
            perror("send error.");
            break;
        }
    }

    close(client); // 关闭客户端 socket
    return nullptr;
}

int main()
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("socket error.");
        exit(-1);
    }

    struct sockaddr_in socket_addr;
    memset(&socket_addr, 0, sizeof(socket_addr));
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socket_addr.sin_port = htons(5555);

    if (bind(socket_fd, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) == -1)
    {
        perror("bind error.");
        exit(-1);
    }

    if (listen(socket_fd, 5) == -1)
    {
        perror("listen error.");
        exit(-1);
    }

    while (true)
    {
        cout << "等待连接...\n";
        sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int *client = new int;
        *client = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (*client == -1)
        {
            perror("accept error.");
            delete client; // 清理内存
            continue;
        }

        cout << "接受到一个连接: " << inet_ntoa(client_addr.sin_addr) << endl;

        // 创建线程来单独处理
        pthread_t tid;
        if (pthread_create(&tid, nullptr, handle_client, client) != 0)
        {
            perror("pthread_create error.");
            close(*client);
            delete client; // 清理内存
            continue;
        }
        pthread_detach(tid); // 分离线程，自动回收资源
    }

    close(socket_fd);
    return 0;
}
