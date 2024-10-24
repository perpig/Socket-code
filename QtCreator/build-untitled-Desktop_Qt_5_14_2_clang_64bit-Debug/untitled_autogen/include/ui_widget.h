/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *TitleTXT;
    QTextEdit *cmdLineSendServerEdit;
    QTextBrowser *showRevServer;
    QLabel *RevServerTXT;
    QTextBrowser *showSituation;
    QLabel *SendserverTXT;
    QLabel *SituationTXT;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *IDcmdLineEdit;
    QLabel *ServerIpTXT;
    QLineEdit *cmdLineServerIPEdit;
    QLabel *portTXT;
    QLineEdit *cmdLinePortEdit;
    QPushButton *connectButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *privateSendButton;
    QPushButton *sendButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *cancleButton;
    QPushButton *CloseButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *sendUserEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(496, 495);
        Widget->setStyleSheet(QString::fromUtf8("background-color: lightpink"));
        TitleTXT = new QLabel(Widget);
        TitleTXT->setObjectName(QString::fromUtf8("TitleTXT"));
        TitleTXT->setGeometry(QRect(170, 10, 191, 21));
        QFont font;
        font.setPointSize(19);
        TitleTXT->setFont(font);
        TitleTXT->setMargin(1);
        cmdLineSendServerEdit = new QTextEdit(Widget);
        cmdLineSendServerEdit->setObjectName(QString::fromUtf8("cmdLineSendServerEdit"));
        cmdLineSendServerEdit->setGeometry(QRect(260, 100, 221, 111));
        cmdLineSendServerEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));
        showRevServer = new QTextBrowser(Widget);
        showRevServer->setObjectName(QString::fromUtf8("showRevServer"));
        showRevServer->setGeometry(QRect(20, 210, 221, 131));
        showRevServer->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        RevServerTXT = new QLabel(Widget);
        RevServerTXT->setObjectName(QString::fromUtf8("RevServerTXT"));
        RevServerTXT->setGeometry(QRect(20, 180, 101, 16));
        showSituation = new QTextBrowser(Widget);
        showSituation->setObjectName(QString::fromUtf8("showSituation"));
        showSituation->setGeometry(QRect(20, 370, 351, 111));
        showSituation->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        SendserverTXT = new QLabel(Widget);
        SendserverTXT->setObjectName(QString::fromUtf8("SendserverTXT"));
        SendserverTXT->setGeometry(QRect(260, 80, 161, 16));
        SituationTXT = new QLabel(Widget);
        SituationTXT->setObjectName(QString::fromUtf8("SituationTXT"));
        SituationTXT->setGeometry(QRect(20, 350, 81, 16));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 40, 188, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        IDcmdLineEdit = new QLineEdit(layoutWidget);
        IDcmdLineEdit->setObjectName(QString::fromUtf8("IDcmdLineEdit"));
        IDcmdLineEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));

        horizontalLayout_2->addWidget(IDcmdLineEdit);

        ServerIpTXT = new QLabel(Widget);
        ServerIpTXT->setObjectName(QString::fromUtf8("ServerIpTXT"));
        ServerIpTXT->setGeometry(QRect(20, 80, 92, 21));
        cmdLineServerIPEdit = new QLineEdit(Widget);
        cmdLineServerIPEdit->setObjectName(QString::fromUtf8("cmdLineServerIPEdit"));
        cmdLineServerIPEdit->setGeometry(QRect(120, 80, 111, 21));
        cmdLineServerIPEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        portTXT = new QLabel(Widget);
        portTXT->setObjectName(QString::fromUtf8("portTXT"));
        portTXT->setGeometry(QRect(20, 110, 44, 21));
        cmdLinePortEdit = new QLineEdit(Widget);
        cmdLinePortEdit->setObjectName(QString::fromUtf8("cmdLinePortEdit"));
        cmdLinePortEdit->setGeometry(QRect(120, 110, 111, 21));
        cmdLinePortEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));
        connectButton = new QPushButton(Widget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(30, 140, 201, 31));
        connectButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 270, 137, 71));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        privateSendButton = new QPushButton(layoutWidget1);
        privateSendButton->setObjectName(QString::fromUtf8("privateSendButton"));
        privateSendButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));

        verticalLayout->addWidget(privateSendButton);

        sendButton = new QPushButton(layoutWidget1);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setStyleSheet(QString::fromUtf8("background-color: white;"));

        verticalLayout->addWidget(sendButton);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(380, 400, 95, 66));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        cancleButton = new QPushButton(layoutWidget2);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        cancleButton->setStyleSheet(QString::fromUtf8("background-color: white;"));

        verticalLayout_2->addWidget(cancleButton);

        CloseButton = new QPushButton(layoutWidget2);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setStyleSheet(QString::fromUtf8("background-color: white;"));

        verticalLayout_2->addWidget(CloseButton);

        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(260, 230, 221, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        sendUserEdit = new QLineEdit(layoutWidget3);
        sendUserEdit->setObjectName(QString::fromUtf8("sendUserEdit"));
        sendUserEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));

        horizontalLayout_3->addWidget(sendUserEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Client", nullptr));
        TitleTXT->setText(QCoreApplication::translate("Widget", "Client\345\256\242\346\210\267\347\253\257\347\225\214\351\235\242", nullptr));
        RevServerTXT->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\210\260\344\277\241\346\201\257\357\274\232", nullptr));
        SendserverTXT->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\246\201\345\217\221\351\200\201\347\232\204\344\277\241\346\201\257\357\274\232", nullptr));
        SituationTXT->setText(QCoreApplication::translate("Widget", "\347\212\266\346\200\201\345\217\212\350\276\223\345\207\272\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        ServerIpTXT->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        portTXT->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267:", nullptr));
        connectButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        privateSendButton->setText(QCoreApplication::translate("Widget", "\347\247\201\345\217\221", nullptr));
        sendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\347\273\231\346\234\215\345\212\241\345\231\250", nullptr));
        cancleButton->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        CloseButton->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\247\201\345\217\221\350\207\263\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
