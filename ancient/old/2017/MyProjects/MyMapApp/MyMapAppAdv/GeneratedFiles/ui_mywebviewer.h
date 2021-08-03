/********************************************************************************
** Form generated from reading UI file 'mywebviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWEBVIEWER_H
#define UI_MYWEBVIEWER_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MyWebViewer
{
public:

    void setupUi(QWebView *MyWebViewer)
    {
        if (MyWebViewer->objectName().isEmpty())
            MyWebViewer->setObjectName(QStringLiteral("MyWebViewer"));
        MyWebViewer->resize(400, 300);

        retranslateUi(MyWebViewer);

        QMetaObject::connectSlotsByName(MyWebViewer);
    } // setupUi

    void retranslateUi(QWebView *MyWebViewer)
    {
        MyWebViewer->setWindowTitle(QApplication::translate("MyWebViewer", "MyWebViewer", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWebViewer: public Ui_MyWebViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWEBVIEWER_H
