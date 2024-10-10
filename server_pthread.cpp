#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

using namespace std;

void *handle_client(void *client_socket)
{
    int client = *(int *)client_socket;
    char revData[255];

    while (true)
    {
        ssize_t ret = recv(client, revData, sizeof(revData), 0);
        if (ret <= 0)
        {
            perror("recv error or client disconnected.");
            break;
        }
        cout << "显示接收数据：" << revData << endl;

        // 发送回应
        char sentData[255];
        cout << "键入发送信息: ";
        cin >> sentData;

        if (send(client, sentData, strlen(sentData), 0) < 0)
        {
            perror("send error.");
            break;
        }
    }

    close(client);
    delete (int *)client; // 清理内存
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

        pthread_t tid;
        if (pthread_create(&tid, nullptr, handle_client, client) != 0)
        {
            perror("pthread_create error.");
            close(*client);
            delete client; // 清理内存
        }
        pthread_detach(tid); // 分离线程，自动回收资源
    }

    close(socket_fd);
    return 0;
}
