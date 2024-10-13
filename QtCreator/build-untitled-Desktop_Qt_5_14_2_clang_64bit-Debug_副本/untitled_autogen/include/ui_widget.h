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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *sendButton;
    QLabel *TitleTXT;
    QTextEdit *cmdLineSendServerEdit;
    QTextBrowser *showRevServer;
    QLabel *RevServerTXT;
    QTextBrowser *showSituation;
    QLabel *SendserverTXT;
    QLabel *SituationTXT;
    QPushButton *CloseButton;
    QPushButton *cancleButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *ServerIpTXT;
    QLineEdit *cmdLineServerIPEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *portTXT;
    QLineEdit *cmdLinePortEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *IDcmdLineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(491, 347);
        Widget->setStyleSheet(QString::fromUtf8("background-color: lightpink"));
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(370, 230, 113, 32));
        sendButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        TitleTXT = new QLabel(Widget);
        TitleTXT->setObjectName(QString::fromUtf8("TitleTXT"));
        TitleTXT->setGeometry(QRect(160, 10, 191, 21));
        QFont font;
        font.setPointSize(19);
        TitleTXT->setFont(font);
        TitleTXT->setMargin(1);
        cmdLineSendServerEdit = new QTextEdit(Widget);
        cmdLineSendServerEdit->setObjectName(QString::fromUtf8("cmdLineSendServerEdit"));
        cmdLineSendServerEdit->setGeometry(QRect(250, 120, 221, 101));
        cmdLineSendServerEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));
        showRevServer = new QTextBrowser(Widget);
        showRevServer->setObjectName(QString::fromUtf8("showRevServer"));
        showRevServer->setGeometry(QRect(20, 120, 221, 101));
        showRevServer->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        RevServerTXT = new QLabel(Widget);
        RevServerTXT->setObjectName(QString::fromUtf8("RevServerTXT"));
        RevServerTXT->setGeometry(QRect(20, 100, 101, 16));
        showSituation = new QTextBrowser(Widget);
        showSituation->setObjectName(QString::fromUtf8("showSituation"));
        showSituation->setGeometry(QRect(20, 250, 281, 91));
        showSituation->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        SendserverTXT = new QLabel(Widget);
        SendserverTXT->setObjectName(QString::fromUtf8("SendserverTXT"));
        SendserverTXT->setGeometry(QRect(250, 100, 161, 16));
        SituationTXT = new QLabel(Widget);
        SituationTXT->setObjectName(QString::fromUtf8("SituationTXT"));
        SituationTXT->setGeometry(QRect(20, 230, 81, 16));
        CloseButton = new QPushButton(Widget);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setGeometry(QRect(370, 270, 113, 32));
        CloseButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        cancleButton = new QPushButton(Widget);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        cancleButton->setGeometry(QRect(370, 310, 113, 32));
        cancleButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 484, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ServerIpTXT = new QLabel(widget);
        ServerIpTXT->setObjectName(QString::fromUtf8("ServerIpTXT"));

        horizontalLayout->addWidget(ServerIpTXT);

        cmdLineServerIPEdit = new QLineEdit(widget);
        cmdLineServerIPEdit->setObjectName(QString::fromUtf8("cmdLineServerIPEdit"));
        cmdLineServerIPEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout->addWidget(cmdLineServerIPEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        portTXT = new QLabel(widget);
        portTXT->setObjectName(QString::fromUtf8("portTXT"));

        horizontalLayout->addWidget(portTXT);

        cmdLinePortEdit = new QLineEdit(widget);
        cmdLinePortEdit->setObjectName(QString::fromUtf8("cmdLinePortEdit"));
        cmdLinePortEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));

        horizontalLayout->addWidget(cmdLinePortEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout->addWidget(connectButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(160, 30, 188, 23));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        IDcmdLineEdit = new QLineEdit(widget1);
        IDcmdLineEdit->setObjectName(QString::fromUtf8("IDcmdLineEdit"));
        IDcmdLineEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));

        horizontalLayout_2->addWidget(IDcmdLineEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Client", nullptr));
        sendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        TitleTXT->setText(QCoreApplication::translate("Widget", "Client\345\256\242\346\210\267\347\253\257\347\225\214\351\235\242", nullptr));
        RevServerTXT->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", nullptr));
        SendserverTXT->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\246\201\345\217\221\351\200\201\350\207\263\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", nullptr));
        SituationTXT->setText(QCoreApplication::translate("Widget", "\347\212\266\346\200\201\345\217\212\350\276\223\345\207\272\357\274\232", nullptr));
        CloseButton->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        cancleButton->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        ServerIpTXT->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        portTXT->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267:", nullptr));
        connectButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
