#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , socket(new QTcpSocket) //创建初始化Socket对象
{
    ui->setupUi(this);

    connect(ui->cancleButton, &QPushButton::clicked, this, &Widget::close);

    connect(socket, &QTcpSocket::readyRead, this, &Widget::onServerDataReceived);

}

Widget::~Widget()
{
    delete ui;
    delete socket;
}


void Widget::on_connectButton_clicked()
//连接按钮
{

    // 每次重新连接前断开之前的连接，防止多次绑定然后发很多次消息
    disconnect(socket, &QTcpSocket::connected, this, nullptr);
    disconnect(socket, &QTcpSocket::disconnected, this, nullptr);

    //获取lienedit 的ip和port
    QString port = ui->cmdLinePortEdit->text();
    QString ip = ui->cmdLineServerIPEdit->text();

    //函数原型[virtual] void QAbstractSocket::connectToHost(const QHostAddress &address, quint16 port, QIODevice::OpenMode openMode = ReadWrite)
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 连接服务器之后发出 connected 的信号
    connect(socket, &QTcpSocket::connected, this, [this]() {
        ui->showSituation->append("连接成功！");

        // 获取用户名
        QString username = ui->IDcmdLineEdit->text(); // 添加用户名输入框
        socket->write(username.toUtf8()); // 发送用户名

    }, Qt::UniqueConnection);

    // 连接断开之后发出 disconnected 的信号
    connect(socket, &QTcpSocket::disconnected, this, [this]() {
        ui->showSituation->append("断开连接！");
    }, Qt::UniqueConnection);

}


void Widget::on_sendButton_clicked()
//发送按钮
{
    // 获取文本框内容
    QString sendText = ui->cmdLineSendServerEdit->toPlainText();
    qint64 bytes = socket->write(sendText.toUtf8());  // 使用 UTF-8 编码发送数据

    if(bytes < 0)
    {
        ui->showSituation->append("发送失败！");
    }
    else
    {
        // 每次重新连接前断开之前的连接，防止多次绑定然后发很多次消息
        disconnect(socket, &QTcpSocket::bytesWritten, this, nullptr);
        // 连接 bytesWritten 信号，当数据成功写入时触发
        connect(socket, &QTcpSocket::bytesWritten, this, [this, sendText](qint64)
        {
             ui->showSituation->append("发送成功:" + sendText);
             ui->cmdLineSendServerEdit->clear();  // 清空输入框
        });
    }
}


void Widget::on_CloseButton_clicked()
{
    // 每次重新连接前断开之前的连接，防止多次绑定然后发很多次消息
    disconnect(socket, &QTcpSocket::disconnected, this, nullptr);
    // 连接断开后显示断开信息
    connect(socket, &QTcpSocket::disconnected, this, [this]()
    {
        ui->showSituation->append("断开连接！");
    });

    // 关闭 socket 连接
    socket->close();
}


void Widget::onServerDataReceived()
// 处理服务器发送数据的槽函数
{
    // 从服务器读取所有可用的数据
    //原来的 C++ socket 代码使用了 recv() 来接收数据，在 Qt 中用readAll()就够了
    QByteArray serverData = socket->readAll();

    // 将数据追加到 QTextBrowser 中
    ui->showRevServer->append(QString::fromUtf8(serverData));
    // 更新状态
    ui->showSituation->append("接受到服务器发送的数据.");

}


