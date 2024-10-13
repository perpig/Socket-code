/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

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

class Ui_server
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *SendButton;
    QTextEdit *sendTextEdit;
    QPushButton *CloseButton;
    QTextBrowser *recvTextBrowser;
    QLabel *label_6;
    QTextBrowser *ShowSituation;
    QLabel *label_7;
    QTextBrowser *showClientSituation;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QLineEdit *IPLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QPushButton *CreateButton;

    void setupUi(QWidget *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QString::fromUtf8("server"));
        server->resize(519, 358);
        server->setStyleSheet(QString::fromUtf8("background-color: lightblue;\n"
""));
        label = new QLabel(server);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 10, 171, 16));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(server);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 70, 121, 16));
        label_5 = new QLabel(server);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 70, 81, 21));
        SendButton = new QPushButton(server);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setGeometry(QRect(390, 200, 113, 32));
        SendButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        sendTextEdit = new QTextEdit(server);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(270, 90, 231, 111));
        sendTextEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        CloseButton = new QPushButton(server);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setGeometry(QRect(400, 0, 113, 32));
        CloseButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        recvTextBrowser = new QTextBrowser(server);
        recvTextBrowser->setObjectName(QString::fromUtf8("recvTextBrowser"));
        recvTextBrowser->setGeometry(QRect(20, 90, 231, 111));
        recvTextBrowser->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        label_6 = new QLabel(server);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 230, 71, 16));
        ShowSituation = new QTextBrowser(server);
        ShowSituation->setObjectName(QString::fromUtf8("ShowSituation"));
        ShowSituation->setGeometry(QRect(20, 250, 231, 101));
        ShowSituation->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        label_7 = new QLabel(server);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 230, 91, 16));
        showClientSituation = new QTextBrowser(server);
        showClientSituation->setObjectName(QString::fromUtf8("showClientSituation"));
        showClientSituation->setGeometry(QRect(270, 250, 231, 101));
        showClientSituation->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        layoutWidget = new QWidget(server);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 491, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        IPLineEdit = new QLineEdit(layoutWidget);
        IPLineEdit->setObjectName(QString::fromUtf8("IPLineEdit"));
        IPLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout->addWidget(IPLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        portLineEdit = new QLineEdit(layoutWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setMaximumSize(QSize(97, 16777215));
        portLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout->addWidget(portLineEdit);

        CreateButton = new QPushButton(layoutWidget);
        CreateButton->setObjectName(QString::fromUtf8("CreateButton"));
        CreateButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout->addWidget(CreateButton);


        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QWidget *server)
    {
        server->setWindowTitle(QCoreApplication::translate("server", "server", nullptr));
        label->setText(QCoreApplication::translate("server", "Server\346\234\215\345\212\241\345\231\250\347\253\257\347\225\214\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("server", "\350\276\223\345\205\245\345\271\277\346\222\255\345\217\221\351\200\201\344\277\241\346\201\257\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("server", "\346\216\245\345\217\227\345\210\260\344\277\241\346\201\257\357\274\232", nullptr));
        SendButton->setText(QCoreApplication::translate("server", "\345\271\277\346\222\255", nullptr));
        CloseButton->setText(QCoreApplication::translate("server", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", nullptr));
        label_6->setText(QCoreApplication::translate("server", "\347\212\266\346\200\201\345\217\212\350\276\223\345\207\272\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("server", "\347\233\256\345\211\215\350\277\236\346\216\245\346\203\205\345\206\265\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("server", "\346\234\254\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("server", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        CreateButton->setText(QCoreApplication::translate("server", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
