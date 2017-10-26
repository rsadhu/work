/********************************************************************************
** Form generated from reading UI file 'dragndrop.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGNDROP_H
#define UI_DRAGNDROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragNDropClass
{
public:

    void setupUi(QWidget *DragNDropClass)
    {
        if (DragNDropClass->objectName().isEmpty())
            DragNDropClass->setObjectName(QStringLiteral("DragNDropClass"));
        DragNDropClass->resize(600, 400);

        retranslateUi(DragNDropClass);

        QMetaObject::connectSlotsByName(DragNDropClass);
    } // setupUi

    void retranslateUi(QWidget *DragNDropClass)
    {
        DragNDropClass->setWindowTitle(QApplication::translate("DragNDropClass", "DragNDrop", 0));
    } // retranslateUi

};

namespace Ui {
    class DragNDropClass: public Ui_DragNDropClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGNDROP_H
