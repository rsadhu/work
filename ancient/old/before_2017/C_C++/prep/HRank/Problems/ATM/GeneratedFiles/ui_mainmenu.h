/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QTextEdit *lineEdit;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(244, 372);
        pushButton = new QPushButton(MainMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 20, 81, 81));
        pushButton_2 = new QPushButton(MainMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 100, 81, 81));
        pushButton_4 = new QPushButton(MainMenu);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 260, 81, 81));
        pushButton_3 = new QPushButton(MainMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 180, 81, 81));
        lineEdit = new QTextEdit(MainMenu);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 141, 321));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", 0));
        pushButton->setText(QApplication::translate("MainMenu", "Balance", 0));
        pushButton_2->setText(QApplication::translate("MainMenu", "Withdraw", 0));
        pushButton_4->setText(QApplication::translate("MainMenu", "Mini Statement", 0));
        pushButton_3->setText(QApplication::translate("MainMenu", "Pin Change", 0));
    } // retranslateUi
};

namespace Ui
{
    class MainMenu : public Ui_MainMenu
    {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
