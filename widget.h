#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QTcpSocket>
#include <QHostAddress> //主机地址 ，ip等

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    // 槽函数都要加slots
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void on_CloseButton_clicked();

    void onServerDataReceived();  // 处理服务器发送数据的槽函数

private:
    Ui::Widget *ui;
    QTcpSocket *socket;  // 创建一个 QTcpSocket 对象
};
#endif // WIDGET_H
