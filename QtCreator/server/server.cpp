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
// 发送信息
{
    // 获取send的内容
    auto sendMessage = ui->sendTextEdit->toPlainText();

    // 如果发送的内容为空，则不执行任何操作
    if (sendMessage.isEmpty())
    {
        ui->ShowSituation->append("发送的内容为空，无法发送。");
        return;
    }

    // 遍历所有连接的客户端并发送消息
    for (const struct ID_IP &clientID_IP : connectedClients)
    {
        // 发送消息
        clientID_IP.socket->write(sendMessage.toUtf8());
    }

    // 显示发送的信息到UI
    ui->ShowSituation->append("成功广播消息: " + sendMessage);
    ui->sendTextEdit->clear(); // 清空发送框
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

        // 连接客户端的信号，以处理数据接收
        connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket, user]() {
            QByteArray data = clientSocket->readAll();
            ui->ShowSituation->append("接收到来自客户端" + user.id + "(" + user.ip + ")" + " 的消息.");
            ui->recvTextBrowser->append(QString::fromUtf8(data));
        }); });

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
