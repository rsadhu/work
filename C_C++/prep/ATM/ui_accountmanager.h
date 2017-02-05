/********************************************************************************
** Form generated from reading UI file 'accountmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGER_H
#define UI_ACCOUNTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountManagerClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;

    void setupUi(QWidget *AccountManagerClass)
    {
        if (AccountManagerClass->objectName().isEmpty())
            AccountManagerClass->setObjectName(QStringLiteral("AccountManagerClass"));
        AccountManagerClass->resize(289, 337);
        gridLayout_2 = new QGridLayout(AccountManagerClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(AccountManagerClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(AccountManagerClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(AccountManagerClass);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(AccountManagerClass);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(AccountManagerClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton);

        retranslateUi(AccountManagerClass);

        QMetaObject::connectSlotsByName(AccountManagerClass);
    } // setupUi

    void retranslateUi(QWidget *AccountManagerClass)
    {
        AccountManagerClass->setWindowTitle(QApplication::translate("AccountManagerClass", "AccountManager", 0));
        pushButton->setText(QApplication::translate("AccountManagerClass", "Enter  PinCode", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountManagerClass: public Ui_AccountManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGER_H
