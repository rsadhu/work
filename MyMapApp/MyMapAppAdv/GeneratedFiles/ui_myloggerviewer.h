/********************************************************************************
** Form generated from reading UI file 'myloggerviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOGGERVIEWER_H
#define UI_MYLOGGERVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLoggerViewer
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MyLoggerViewer)
    {
        if (MyLoggerViewer->objectName().isEmpty())
            MyLoggerViewer->setObjectName(QStringLiteral("MyLoggerViewer"));
        MyLoggerViewer->resize(645, 659);
        gridLayout = new QGridLayout(MyLoggerViewer);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(MyLoggerViewer);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(MyLoggerViewer);

        QMetaObject::connectSlotsByName(MyLoggerViewer);
    } // setupUi

    void retranslateUi(QWidget *MyLoggerViewer)
    {
        MyLoggerViewer->setWindowTitle(QApplication::translate("MyLoggerViewer", "MyLoggerViewer", 0));
    } // retranslateUi

};

namespace Ui {
    class MyLoggerViewer: public Ui_MyLoggerViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOGGERVIEWER_H
