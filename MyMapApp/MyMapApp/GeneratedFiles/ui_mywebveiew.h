/********************************************************************************
** Form generated from reading UI file 'mywebveiew.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWEBVEIEW_H
#define UI_MYWEBVEIEW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MyWebVeiew
{
public:

    void setupUi(QWebView *MyWebVeiew)
    {
        if (MyWebVeiew->objectName().isEmpty())
            MyWebVeiew->setObjectName(QStringLiteral("MyWebVeiew"));
        MyWebVeiew->resize(400, 300);

        retranslateUi(MyWebVeiew);

        QMetaObject::connectSlotsByName(MyWebVeiew);
    } // setupUi

    void retranslateUi(QWebView *MyWebVeiew)
    {
        MyWebVeiew->setWindowTitle(QApplication::translate("MyWebVeiew", "MyWebVeiew", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWebVeiew: public Ui_MyWebVeiew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWEBVEIEW_H
