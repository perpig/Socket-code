#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QProcess>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress> //主机地址 ，ip等
#include <QSet>         //存储连接的客户端ip
#include <QHash>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class server;
}
QT_END_NAMESPACE

struct ID_IP
{
    QString ip; // 用户名
    QString id;
    QTcpSocket *socket; // 用于唯一标识客户端的指针

    ID_IP(QString tid, QString tip, QTcpSocket *tsocket)
        : id(tid), ip(tip), socket(tsocket) {}

    // 重载==操作符
    bool operator==(const ID_IP &other) const
    {
        return id == other.id && ip == other.ip && socket == other.socket;
    }
};

// 为 ID_IP 类型提供 qHash 函数特化
inline uint qHash(const ID_IP &key, uint seed = 0)
{
    return qHash(key.id, seed) ^ qHash(key.ip, seed);
}

class server : public QWidget
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();

private slots:

    void on_CreateButton_clicked();

    void on_SendButton_clicked();

    void onNewConnection();

    void updateShowClientsLists();

private:
    Ui::server *ui;
    QTcpServer *server_socket;
    QSet<struct ID_IP> connectedClients; // 用于存储连接的客户端IP地址和ID
};
#endif // SERVER_H
