/********************************************************************************
** Form generated from reading UI file 'ChatServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSERVER_H
#define UI_CHATSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatServerClass
{
public:
    QAction *actionOpen;
    QAction *actionF1;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuLogs;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatServerClass)
    {
        if (ChatServerClass->objectName().isEmpty())
            ChatServerClass->setObjectName(QStringLiteral("ChatServerClass"));
        ChatServerClass->resize(343, 268);
        actionOpen = new QAction(ChatServerClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionF1 = new QAction(ChatServerClass);
        actionF1->setObjectName(QStringLiteral("actionF1"));
        centralWidget = new QWidget(ChatServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        ChatServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 343, 21));
        menuLogs = new QMenu(menuBar);
        menuLogs->setObjectName(QStringLiteral("menuLogs"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        ChatServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatServerClass->setStatusBar(statusBar);

        menuBar->addAction(menuLogs->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuLogs->addAction(actionOpen);
        menuHelp->addAction(actionF1);

        retranslateUi(ChatServerClass);

        QMetaObject::connectSlotsByName(ChatServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatServerClass)
    {
        ChatServerClass->setWindowTitle(QApplication::translate("ChatServerClass", "ChatServer", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ChatServerClass", "Open", Q_NULLPTR));
        actionF1->setText(QApplication::translate("ChatServerClass", "F1", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("ChatServerClass", "Start", Q_NULLPTR));
        menuLogs->setTitle(QApplication::translate("ChatServerClass", "Logs", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("ChatServerClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatServerClass: public Ui_ChatServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSERVER_H
