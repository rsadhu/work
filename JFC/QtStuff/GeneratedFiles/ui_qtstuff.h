/********************************************************************************
** Form generated from reading UI file 'qtstuff.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTUFF_H
#define UI_QTSTUFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtStuffClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *QtStuffClass)
    {
        if (QtStuffClass->objectName().isEmpty())
            QtStuffClass->setObjectName(QStringLiteral("QtStuffClass"));
        QtStuffClass->resize(668, 445);
        gridLayout = new QGridLayout(QtStuffClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(QtStuffClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(QtStuffClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(QtStuffClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(QtStuffClass);

        QMetaObject::connectSlotsByName(QtStuffClass);
    } // setupUi

    void retranslateUi(QWidget *QtStuffClass)
    {
        QtStuffClass->setWindowTitle(QApplication::translate("QtStuffClass", "QtStuff", 0));
        pushButton->setText(QApplication::translate("QtStuffClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("QtStuffClass", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("QtStuffClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class QtStuffClass: public Ui_QtStuffClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTUFF_H
