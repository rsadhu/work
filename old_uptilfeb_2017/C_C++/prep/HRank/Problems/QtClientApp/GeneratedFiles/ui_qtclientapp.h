/********************************************************************************
** Form generated from reading UI file 'qtclientapp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLIENTAPP_H
#define UI_QTCLIENTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtClientAppClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *wDisplay;
    QHBoxLayout *horizontalLayout;
    QPushButton *Connect;
    QPushButton *SendData;

    void setupUi(QWidget *QtClientAppClass)
    {
        if (QtClientAppClass->objectName().isEmpty())
            QtClientAppClass->setObjectName(QStringLiteral("QtClientAppClass"));
        QtClientAppClass->resize(600, 400);
        gridLayout = new QGridLayout(QtClientAppClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        wDisplay = new QWidget(QtClientAppClass);
        wDisplay->setObjectName(QStringLiteral("wDisplay"));

        verticalLayout->addWidget(wDisplay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Connect = new QPushButton(QtClientAppClass);
        Connect->setObjectName(QStringLiteral("Connect"));

        horizontalLayout->addWidget(Connect);

        SendData = new QPushButton(QtClientAppClass);
        SendData->setObjectName(QStringLiteral("SendData"));

        horizontalLayout->addWidget(SendData);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(QtClientAppClass);

        QMetaObject::connectSlotsByName(QtClientAppClass);
    } // setupUi

    void retranslateUi(QWidget *QtClientAppClass)
    {
        QtClientAppClass->setWindowTitle(QApplication::translate("QtClientAppClass", "QtClientApp", 0));
        Connect->setText(QApplication::translate("QtClientAppClass", "Connect", 0));
        SendData->setText(QApplication::translate("QtClientAppClass", "SendData", 0));
    } // retranslateUi

};

namespace Ui {
    class QtClientAppClass: public Ui_QtClientAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLIENTAPP_H
