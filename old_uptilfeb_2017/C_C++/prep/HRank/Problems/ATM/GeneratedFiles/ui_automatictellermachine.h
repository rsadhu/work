/********************************************************************************
** Form generated from reading UI file 'automatictellermachine.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOMATICTELLERMACHINE_H
#define UI_AUTOMATICTELLERMACHINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutomaticTellerMachineClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;

    void setupUi(QWidget *AutomaticTellerMachineClass)
    {
        if (AutomaticTellerMachineClass->objectName().isEmpty())
            AutomaticTellerMachineClass->setObjectName(QStringLiteral("AutomaticTellerMachineClass"));
        AutomaticTellerMachineClass->resize(256, 379);
        gridLayout = new QGridLayout(AutomaticTellerMachineClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(AutomaticTellerMachineClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(AutomaticTellerMachineClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(AutomaticTellerMachineClass);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(AutomaticTellerMachineClass);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(AutomaticTellerMachineClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AutomaticTellerMachineClass);

        QMetaObject::connectSlotsByName(AutomaticTellerMachineClass);
    } // setupUi

    void retranslateUi(QWidget *AutomaticTellerMachineClass)
    {
        AutomaticTellerMachineClass->setWindowTitle(QApplication::translate("AutomaticTellerMachineClass", "AutomaticTellerMachine", 0));
        pushButton->setText(QApplication::translate("AutomaticTellerMachineClass", "Enter Pin", 0));
    } // retranslateUi

};

namespace Ui {
    class AutomaticTellerMachineClass: public Ui_AutomaticTellerMachineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOMATICTELLERMACHINE_H
