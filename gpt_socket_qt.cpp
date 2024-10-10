// // // Qt图形界面
// #include <QApplication>
// #include <QWidget>
// #include <QVBoxLayout>
// #include <QLineEdit>
// #include <QPushButton>
// #include <QTextEdit>
// #include <QTcpSocket>
// #include <QHostAddress>
// #include <QMessageBox>

// class SocketClient : public QWidget
// {
//     Q_OBJECT

// public:
//     SocketClient(QWidget *parent = nullptr) : QWidget(parent)
//     {
//         QVBoxLayout *layout = new QVBoxLayout(this);

//         // 输入服务器 IP 的输入框
//         serverInput = new QLineEdit(this);
//         serverInput->setPlaceholderText("输入服务器 IP...");
//         layout->addWidget(serverInput);

//         // 创建连接按钮
//         QPushButton *connectButton = new QPushButton("连接", this);
//         layout->addWidget(connectButton);

//         // 创建输入框
//         messageInput = new QLineEdit(this);
//         messageInput->setPlaceholderText("输入消息...");
//         layout->addWidget(messageInput);

//         // 创建发送按钮
//         QPushButton *sendButton = new QPushButton("发送", this);
//         layout->addWidget(sendButton);

//         // 创建接收消息的文本区域
//         messageDisplay = new QTextEdit(this);
//         messageDisplay->setReadOnly(true);
//         layout->addWidget(messageDisplay);

//         // 创建状态信息的文本区域
//         statusDisplay = new QTextEdit(this);
//         statusDisplay->setReadOnly(true);
//         layout->addWidget(statusDisplay);

//         // 创建断开连接按钮
//         QPushButton *disconnectButton = new QPushButton("断开连接", this);
//         layout->addWidget(disconnectButton);

//         socket = new QTcpSocket(this);

//         // 连接信号和槽
//         connect(connectButton, &QPushButton::clicked, this, &SocketClient::connectToServer);
//         connect(sendButton, &QPushButton::clicked, this, &SocketClient::sendMessage);
//         connect(socket, &QTcpSocket::readyRead, this, &SocketClient::receiveMessage);
//         connect(disconnectButton, &QPushButton::clicked, this, &SocketClient::disconnectFromServer);
//     }

// private slots:
//     void connectToServer()
//     {
//         QString serverIp = serverInput->text();
//         socket->connectToHost(QHostAddress(serverIp), 5555); // 使用构造函数
//         if (!socket->waitForConnected(3000))
//         {
//             QMessageBox::critical(this, "连接错误", "无法连接到服务器");
//             statusDisplay->append("连接失败: " + serverIp);
//         }
//         else
//         {
//             statusDisplay->append("连接成功: " + serverIp);
//         }
//     }

//     void sendMessage()
//     {
//         QString message = messageInput->text();
//         if (!message.isEmpty())
//         {
//             socket->write(message.toUtf8());
//             messageInput->clear();
//         }
//     }

//     void receiveMessage()
//     {
//         while (socket->canReadLine())
//         {
//             QString line = socket->readLine().trimmed();
//             messageDisplay->append("服务器: " + line);
//         }
//     }

//     void disconnectFromServer()
//     {
//         socket->disconnectFromHost();
//         statusDisplay->append("已断开连接");
//     }

// private:
//     QLineEdit *serverInput;    // 输入服务器 IP 的框
//     QLineEdit *messageInput;   // 输入消息的框
//     QTextEdit *messageDisplay; // 显示接收消息的区域
//     QTextEdit *statusDisplay;  // 显示状态信息的区域
//     QTcpSocket *socket;        // Socket 对象
// };

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     SocketClient client;
//     client.setWindowTitle("Socket 客户端");
//     client.resize(400, 400);
//     client.show();

//     return app.exec();
// }

// #include "gpt_socket_qt.moc"

// ---以上是有ip输入和断开的版本 但是连接不上

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

class SocketClient : public QWidget
{
    Q_OBJECT

public:
    SocketClient(QWidget *parent = nullptr) : QWidget(parent)
    {
        // 设置窗口布局
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建输入框
        messageInput = new QLineEdit(this);
        messageInput->setPlaceholderText("输入消息...");
        layout->addWidget(messageInput);

        // 创建发送按钮
        QPushButton *sendButton = new QPushButton("发送", this);
        layout->addWidget(sendButton);

        // 创建接收消息的文本区域
        messageDisplay = new QTextEdit(this);
        messageDisplay->setReadOnly(true);
        layout->addWidget(messageDisplay);

        // 创建QTcpSocket实例
        socket = new QTcpSocket(this);

        // 连接信号和槽
        connect(sendButton, &QPushButton::clicked, this, &SocketClient::sendMessage);
        connect(socket, &QTcpSocket::readyRead, this, &SocketClient::receiveMessage);

        // 连接到服务器
        connectToServer();
    }

private slots:
    void sendMessage()
    {
        QString message = messageInput->text();
        if (!message.isEmpty())
        {
            socket->write(message.toUtf8());
            messageInput->clear();
        }
    }

    void receiveMessage()
    {
        while (socket->canReadLine())
        {
            QString line = socket->readLine().trimmed();
            messageDisplay->append("服务器: " + line);
        }
    }

private:
    void connectToServer()
    {
        socket->connectToHost(QHostAddress::LocalHost, 5555); // 连接到本地服务器的5555端口
        if (!socket->waitForConnected(3000))
        { // 等待3秒以连接
            QMessageBox::critical(this, "连接错误", "无法连接到服务器");
        }
    }

    QLineEdit *messageInput;
    QTextEdit *messageDisplay;
    QTcpSocket *socket;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SocketClient client;
    client.setWindowTitle("Socket 客户端");
    client.resize(400, 300);
    client.show();

    return app.exec();
}

#include "gpt_socket_qt.moc"
