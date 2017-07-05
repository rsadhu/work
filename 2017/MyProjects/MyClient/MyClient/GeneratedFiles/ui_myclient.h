/********************************************************************************
** Form generated from reading UI file 'myclient.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLIENT_H
#define UI_MYCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClientClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *MyClientClass)
    {
        if (MyClientClass->objectName().isEmpty())
            MyClientClass->setObjectName(QStringLiteral("MyClientClass"));
        MyClientClass->resize(238, 183);
        gridLayout = new QGridLayout(MyClientClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MyClientClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(MyClientClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MyClientClass);

        QMetaObject::connectSlotsByName(MyClientClass);
    } // setupUi

    void retranslateUi(QWidget *MyClientClass)
    {
        MyClientClass->setWindowTitle(QApplication::translate("MyClientClass", "MyClient", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MyClientClass", "send Data", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClientClass: public Ui_MyClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIENT_H
