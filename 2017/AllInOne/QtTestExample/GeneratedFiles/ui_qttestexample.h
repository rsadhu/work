/********************************************************************************
** Form generated from reading UI file 'qttestexample.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTESTEXAMPLE_H
#define UI_QTTESTEXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTestExampleClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *QtTestExampleClass)
    {
        if (QtTestExampleClass->objectName().isEmpty())
            QtTestExampleClass->setObjectName(QStringLiteral("QtTestExampleClass"));
        QtTestExampleClass->resize(600, 400);
        gridLayout = new QGridLayout(QtTestExampleClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(QtTestExampleClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(QtTestExampleClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtTestExampleClass);
    } // setupUi

    void retranslateUi(QWidget *QtTestExampleClass)
    {
        QtTestExampleClass->setWindowTitle(QApplication::translate("QtTestExampleClass", "QtTestExample", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QtTestExampleClass", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QtTestExampleClass", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtTestExampleClass: public Ui_QtTestExampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTESTEXAMPLE_H
