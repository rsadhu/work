/********************************************************************************
** Form generated from reading UI file 'mymapsqt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAPSQT_H
#define UI_MYMAPSQT_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMapsQtClass
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;

    void setupUi(QWidget *MyMapsQtClass)
    {
        if (MyMapsQtClass->objectName().isEmpty())
            MyMapsQtClass->setObjectName(QStringLiteral("MyMapsQtClass"));
        MyMapsQtClass->resize(600, 400);
        gridLayout = new QGridLayout(MyMapsQtClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        webView = new QWebView(MyMapsQtClass);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 1);


        retranslateUi(MyMapsQtClass);

        QMetaObject::connectSlotsByName(MyMapsQtClass);
    } // setupUi

    void retranslateUi(QWidget *MyMapsQtClass)
    {
        MyMapsQtClass->setWindowTitle(QApplication::translate("MyMapsQtClass", "MyMapsQt", 0));
    } // retranslateUi

};

namespace Ui {
    class MyMapsQtClass: public Ui_MyMapsQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAPSQT_H
