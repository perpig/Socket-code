#include "server.h"
#include "./ui_server.h"

server::server(QWidget *parent)
    : QWidget(parent), ui(new Ui::server), server_socket(new QTcpServer(this)) // 创建初始化Socket对象
{
    ui->setupUi(this);

    // 连接信号与槽
    connect(server_socket, &QTcpServer::newConnection, this, &server::onNewConnection);

    // 关闭服务器按钮，关闭该socket以及关闭窗口
    connect(ui->CloseButton, &QPushButton::clicked, this, &server::close);
}

server::~server()
{
    delete ui;
    delete server_socket;
}

void server::on_CreateButton_clicked()
// 启动服务器
{
    // 获取lienedit 的ip和port
    QString port = ui->portLineEdit->text();
    QString ip = ui->IPLineEdit->text();

    // 将端口转换为quint16类型
    quint16 portNumber = static_cast<quint16>(port.toInt());

    // 绑定服务器到指定的IP和端口
    QHostAddress bindaddress(ip);

    // 绑定服务器到指定的IP和端口
    QHostAddress address(ip);
    if (!server_socket->listen(bindaddress, portNumber))
    {
        ui->ShowSituation->append("服务器启动失败: " + server_socket->errorString());
        return;
    }
    ui->ShowSituation->append("服务器成功启动！");
    ui->ShowSituation->append(QString("服务器在 %1:%2 上监听").arg(ip).arg(port));
}

void server::on_SendButton_clicked()
// 广播发送信息
{
    // 获取send的内容
    QString text = ui->sendTextEdit->toPlainText();

    // 如果发送的内容为空，则不执行任何操作
    if (text.isEmpty())
    {
        ui->ShowSituation->append("发送的内容为空，无法发送。");
        return;
    }

    // 格式化
    QString sendMessage = "<msg:" + text + ">";

    // 遍历所有连接的客户端并发送消息
    for (const struct ID_IP &clientID_IP : connectedClients)
    {
        // 发送消息
        clientID_IP.socket->write(sendMessage.toUtf8());
    }

    // 显示发送的信息到UI
    ui->ShowSituation->append("成功广播消息: " + text);
    ui->sendTextEdit->clear(); // 清空发送框
}

void server::on_PrivateSednButton_clicked()
// 处理私发
{
    // 获取send的内容
    auto text = ui->sendTextEdit->toPlainText();

    // 如果发送的内容为空，则不执行任何操作
    if (text.isEmpty())
    {
        ui->ShowSituation->append("发送的内容为空，无法发送。");
        return;
    }

    // 获取私发用户名
    QString SendUser = ui->PrivateSendUser->text();

    // 格式化发送信息
    QString sendMessage = "<msg:" + text + ">";

    int flag = 0;
    // 遍历所有连接的客户端并发送消息
    for (const struct ID_IP &clientID_IP : connectedClients)
    {
        if (SendUser == clientID_IP.id)
        {
            // 发送消息
            clientID_IP.socket->write(sendMessage.toUtf8());
            // 显示发送的信息到UI
            ui->ShowSituation->append("私发用户" + SendUser + "消息: " + text);
            ui->sendTextEdit->clear(); // 清空发送框
            flag++;
        }
    }
    if (!flag)
    {
        // 显示发送失败的信息到UI
        ui->ShowSituation->append("私发用户" + SendUser + "失败：未找到该用户");
    }
}

void server::updateShowClientsLists()
// 更新当前连接的客户端IP列表
{
    ui->showClientSituation->clear(); // 清空之前的显示
    for (const struct ID_IP &clientID_IP : connectedClients)
    {
        ui->showClientSituation->append("User:" + clientID_IP.id + "(" + clientID_IP.ip + ")");
        // 显示所有连接的客户端IP
    }
}

void server::onNewConnection()
// 处理客户端连接
{
    // 获取下一个待处理的连接
    QTcpSocket *clientSocket = server_socket->nextPendingConnection();

    // 获取客户端的IP地址
    QString clientIp = clientSocket->peerAddress().toString();

    // 连接客户端的信号，以处理数据接收
    connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket, clientIp]()
            {
        // 接收用户名
        QString clientId = QString::fromUtf8(clientSocket->readAll());

        // 创建该用户并保存socket指针
        struct ID_IP user = ID_IP(clientId, clientIp, clientSocket);

        // 添加该用户到集合中
        connectedClients.insert(user);

        // 更新列表和状态
        updateShowClientsLists();
        ui->ShowSituation->append("新客户端连接,用户名：" + user.id + "(" + user.ip + ")");

        // 取消与 readyRead 的旧连接，准备接收新的普通消息
        clientSocket->disconnect(SIGNAL(readyRead()));

    //----------------------------------数据接收------------------------------------
    // 连接客户端的信号，以处理数据接收
    connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket, user]() {
            //提取原消息
            QByteArray original_message = clientSocket->readAll();
            QString message = QString::fromUtf8(original_message);


            // 接收的私聊消息格式 "<priv:目标用户名:消息内容>"
            if (message.startsWith("<priv:"))
            {
                int secondColon = message.indexOf(':', 6);    //第二个冒号位置

                if (secondColon != -1)
                // 确保找到了冒号
                {
                    QString targetUser = message.mid(6, secondColon - 6); // 提取目标用户名
                    QString text = message.mid(secondColon + 1, message.length() - secondColon - 2); // 提取私聊消息内容

                    int flag = 0;
                    // 遍历客户端，找到目标用户并发送私聊消息
                    for (const struct ID_IP &clientID_IP : connectedClients)
                    {
                        if (clientID_IP.id == targetUser)
                        {
                            //格式化发送信息<priv:发送用户名：发送信息>
                            QString privateMessage = "<priv:" + user.id + ":" + text + ">";
                            clientID_IP.socket->write(privateMessage.toUtf8());
                            ui->ShowSituation->append("用户" + user.id + "私发消息给用户" + targetUser + " 成功:" + text);
                            flag++;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        ui->ShowSituation->append("转发用户" + user.id + "信息失败: 未找到目标用户 " + targetUser);
                    }

                }
                else
                //没找到冒号 有问题
                {
                    ui->ShowSituation->append("用户" + user.id + "发送过来的私发信息格式有误.");
                }
            }
            else if (message.startsWith("<msg:"))
            // 普通消息处理
            {
                // 普通消息 "<msg:消息内容>"
                QString text = message.mid(5, message.length() - 6);    //提取消息内容

                ui->ShowSituation->append("接收到来自客户端" + user.id + "(" + user.ip + ")" + " 的消息.");
                ui->recvTextBrowser->append("[" + user.id +  "]:" + text);


                //                for (const struct ID_IP &clientID_IP : connectedClients)
                //                {
                //                     QString broadcastMessage = "<msg:" + sender + ": " + message + ">";
                //                      clientID_IP.socket->write(broadcastMessage.toUtf8());
                //                }
                //                   ui->ShowSituation->append("广播消息成功: " + message);
                //                }

            }
            else
            {
                 ui->ShowSituation->append("接收到来自客户端" + user.id + "的消息格式有误：" + message);
            }

    });    });

    // ----------------------------连接断开时的处理---------------------------------------
    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]()
            {
                // 根据socket指针来查找客户端
                auto it = std::find_if(connectedClients.begin(), connectedClients.end(),
                                       [clientSocket](const ID_IP &user)
                                       { return user.socket == clientSocket; });

                // 根据迭代器寻找
                if (it != connectedClients.end())
                {
                    QString userId = it->id;    // 保存要断开用户的ID
                    QString userIp = it->ip;    // 保存要断开用户的IP
                    connectedClients.erase(it); // 集合中移除该用户

                    // 更新列表和状态
                    updateShowClientsLists();
                    ui->ShowSituation->append("客户端:" + userId + "(" + userIp + ")" + " 已断开连接.");
                }

                clientSocket->deleteLater(); // 删除指针，避免内存泄漏
            });
}
