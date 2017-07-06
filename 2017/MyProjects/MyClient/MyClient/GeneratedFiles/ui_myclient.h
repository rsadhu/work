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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyClientClass)
    {
        if (MyClientClass->objectName().isEmpty())
            MyClientClass->setObjectName(QStringLiteral("MyClientClass"));
        MyClientClass->resize(238, 183);
        gridLayout_2 = new QGridLayout(MyClientClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(MyClientClass);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(MyClientClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MyClientClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton_2->raise();
        pushButton_2->raise();
        pushButton->raise();

        retranslateUi(MyClientClass);

        QMetaObject::connectSlotsByName(MyClientClass);
    } // setupUi

    void retranslateUi(QWidget *MyClientClass)
    {
        MyClientClass->setWindowTitle(QApplication::translate("MyClientClass", "MyClient", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MyClientClass", "send Text", 0));
        pushButton_2->setText(QApplication::translate("MyClientClass", "send media", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClientClass: public Ui_MyClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIENT_H
