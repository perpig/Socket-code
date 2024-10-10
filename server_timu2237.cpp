#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

using namespace std;

void handleClient(int client)
{
    char revData[255];
    while (true)
    {
        ssize_t ret = recv(client, revData, sizeof(revData), 0);
        if (ret <= 0)
        {
            perror("recv error.");
            break;
        }
        cout << "显示接收数据：" << revData << endl;

        char sentData[255];
        cout << "键入发送信息:";
        cin >> sentData;

        if (send(client, sentData, strlen(sentData), 0) < 0)
        {
            perror("send error.");
            break;
        }
    }
    close(client);
}

int main()
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socket_fd)
    {
        perror("socket error.");
        exit(-1);
    }

    struct sockaddr_in socket_addr;
    memset(&socket_addr, 0x0, sizeof(socket_addr));
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

    cout << "本服务器ip:" << inet_ntoa(socket_addr.sin_addr) << endl;

    while (true)
    {
        sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int client = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client == -1)
        {
            perror("accept error.");
            continue;
        }
        cout << "接受到一个连接: " << inet_ntoa(client_addr.sin_addr) << endl;

        // 创建线程处理客户端
        std::thread t(handleClient, client);
        t.detach(); // 确保线程可以独立运行
    }

    close(socket_fd);
    return 0;
}
