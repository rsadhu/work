/********************************************************************************
** Form generated from reading UI file 'testoverlapwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOVERLAPWIDGET_H
#define UI_TESTOVERLAPWIDGET_H

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

class Ui_TestOverLapWidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestOverLapWidgetClass)
    {
        if (TestOverLapWidgetClass->objectName().isEmpty())
            TestOverLapWidgetClass->setObjectName(QStringLiteral("TestOverLapWidgetClass"));
        TestOverLapWidgetClass->resize(600, 400);
        menuBar = new QMenuBar(TestOverLapWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TestOverLapWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestOverLapWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestOverLapWidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestOverLapWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestOverLapWidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestOverLapWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestOverLapWidgetClass->setStatusBar(statusBar);

        retranslateUi(TestOverLapWidgetClass);

        QMetaObject::connectSlotsByName(TestOverLapWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestOverLapWidgetClass)
    {
        TestOverLapWidgetClass->setWindowTitle(QApplication::translate("TestOverLapWidgetClass", "TestOverLapWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class TestOverLapWidgetClass: public Ui_TestOverLapWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOVERLAPWIDGET_H
