/********************************************************************************
** Form generated from reading UI file 'ChatClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCLIENT_H
#define UI_CHATCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatClientClass
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *chatClientList;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReconnect;
    QPushButton *btnRefresh;
    QMenuBar *menuBar;
    QMenu *menuQuit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatClientClass)
    {
        if (ChatClientClass->objectName().isEmpty())
            ChatClientClass->setObjectName(QStringLiteral("ChatClientClass"));
        ChatClientClass->resize(259, 390);
        actionLogin = new QAction(ChatClientClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogout = new QAction(ChatClientClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        centralWidget = new QWidget(ChatClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chatClientList = new QTreeWidget(centralWidget);
        chatClientList->headerItem()->setText(0, QString());
        chatClientList->setObjectName(QStringLiteral("chatClientList"));

        verticalLayout->addWidget(chatClientList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnReconnect = new QPushButton(centralWidget);
        btnReconnect->setObjectName(QStringLiteral("btnReconnect"));

        horizontalLayout->addWidget(btnReconnect);

        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));

        horizontalLayout->addWidget(btnRefresh);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        ChatClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 259, 21));
        menuQuit = new QMenu(menuBar);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        ChatClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatClientClass->setStatusBar(statusBar);

        menuBar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionLogin);
        menuQuit->addAction(actionLogout);

        retranslateUi(ChatClientClass);

        QMetaObject::connectSlotsByName(ChatClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatClientClass)
    {
        ChatClientClass->setWindowTitle(QApplication::translate("ChatClientClass", "ChatClient", Q_NULLPTR));
        actionLogin->setText(QApplication::translate("ChatClientClass", "Login", Q_NULLPTR));
        actionLogout->setText(QApplication::translate("ChatClientClass", "Logout", Q_NULLPTR));
        btnReconnect->setText(QApplication::translate("ChatClientClass", "ReConnect", Q_NULLPTR));
        btnRefresh->setText(QApplication::translate("ChatClientClass", "Refresh", Q_NULLPTR));
        menuQuit->setTitle(QApplication::translate("ChatClientClass", "Messenger", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatClientClass: public Ui_ChatClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
