/********************************************************************************
** Form generated from reading UI file 'qtapp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAPP_H
#define UI_QTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtAppClass
{
public:

    void setupUi(QWidget *QtAppClass)
    {
        if (QtAppClass->objectName().isEmpty())
            QtAppClass->setObjectName(QStringLiteral("QtAppClass"));
        QtAppClass->resize(600, 400);

        retranslateUi(QtAppClass);

        QMetaObject::connectSlotsByName(QtAppClass);
    } // setupUi

    void retranslateUi(QWidget *QtAppClass)
    {
        QtAppClass->setWindowTitle(QApplication::translate("QtAppClass", "QtApp", 0));
    } // retranslateUi

};

namespace Ui {
    class QtAppClass: public Ui_QtAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAPP_H
