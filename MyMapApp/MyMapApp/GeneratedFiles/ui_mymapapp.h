/********************************************************************************
** Form generated from reading UI file 'mymapapp.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAPAPP_H
#define UI_MYMAPAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMapAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMapAppClass)
    {
        if (MyMapAppClass->objectName().isEmpty())
            MyMapAppClass->setObjectName(QStringLiteral("MyMapAppClass"));
        MyMapAppClass->resize(600, 400);
        menuBar = new QMenuBar(MyMapAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyMapAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyMapAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyMapAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyMapAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyMapAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyMapAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyMapAppClass->setStatusBar(statusBar);

        retranslateUi(MyMapAppClass);

        QMetaObject::connectSlotsByName(MyMapAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyMapAppClass)
    {
        MyMapAppClass->setWindowTitle(QApplication::translate("MyMapAppClass", "MyMapApp", 0));
    } // retranslateUi

};

namespace Ui {
    class MyMapAppClass: public Ui_MyMapAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAPAPP_H
