/********************************************************************************
** Form generated from reading UI file 'OverLayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAYWIDGET_H
#define UI_OVERLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverLayWidget
{
public:

    void setupUi(QWidget *OverLayWidget)
    {
        if (OverLayWidget->objectName().isEmpty())
            OverLayWidget->setObjectName(QStringLiteral("OverLayWidget"));
        OverLayWidget->resize(400, 300);
        OverLayWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 178, 203);"));

        retranslateUi(OverLayWidget);

        QMetaObject::connectSlotsByName(OverLayWidget);
    } // setupUi

    void retranslateUi(QWidget *OverLayWidget)
    {
        OverLayWidget->setWindowTitle(QApplication::translate("OverLayWidget", "OverLayWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class OverLayWidget: public Ui_OverLayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAYWIDGET_H
