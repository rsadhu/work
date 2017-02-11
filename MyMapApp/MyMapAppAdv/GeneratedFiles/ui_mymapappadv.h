/********************************************************************************
** Form generated from reading UI file 'mymapappadv.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAPAPPADV_H
#define UI_MYMAPAPPADV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMapAppAdvClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *layout_1;
    QWidget *layout_2;
    QWidget *layout_3;
    QWidget *layout_4;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMapAppAdvClass)
    {
        if (MyMapAppAdvClass->objectName().isEmpty())
            MyMapAppAdvClass->setObjectName(QStringLiteral("MyMapAppAdvClass"));
        MyMapAppAdvClass->resize(667, 689);
        centralWidget = new QWidget(MyMapAppAdvClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layout_1 = new QWidget(widget);
        layout_1->setObjectName(QStringLiteral("layout_1"));

        gridLayout->addWidget(layout_1, 0, 0, 1, 1);

        layout_2 = new QWidget(widget);
        layout_2->setObjectName(QStringLiteral("layout_2"));

        gridLayout->addWidget(layout_2, 0, 1, 1, 1);

        layout_3 = new QWidget(widget);
        layout_3->setObjectName(QStringLiteral("layout_3"));

        gridLayout->addWidget(layout_3, 1, 0, 1, 1);

        layout_4 = new QWidget(widget);
        layout_4->setObjectName(QStringLiteral("layout_4"));

        gridLayout->addWidget(layout_4, 1, 1, 1, 1);


        horizontalLayout->addWidget(widget);

        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        horizontalLayout->addWidget(treeWidget);

        horizontalLayout->setStretch(0, 4);
        MyMapAppAdvClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyMapAppAdvClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 21));
        MyMapAppAdvClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyMapAppAdvClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyMapAppAdvClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyMapAppAdvClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyMapAppAdvClass->setStatusBar(statusBar);

        retranslateUi(MyMapAppAdvClass);

        QMetaObject::connectSlotsByName(MyMapAppAdvClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyMapAppAdvClass)
    {
        MyMapAppAdvClass->setWindowTitle(QApplication::translate("MyMapAppAdvClass", "MyMapAppAdv", 0));
    } // retranslateUi

};

namespace Ui {
    class MyMapAppAdvClass: public Ui_MyMapAppAdvClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAPAPPADV_H
