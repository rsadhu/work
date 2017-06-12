/********************************************************************************
** Form generated from reading UI file 'mylayouts.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLAYOUTS_H
#define UI_MYLAYOUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLayouts
{
public:

    void setupUi(QWidget *MyLayouts)
    {
        if (MyLayouts->objectName().isEmpty())
            MyLayouts->setObjectName(QStringLiteral("MyLayouts"));
        MyLayouts->resize(400, 300);

        retranslateUi(MyLayouts);

        QMetaObject::connectSlotsByName(MyLayouts);
    } // setupUi

    void retranslateUi(QWidget *MyLayouts)
    {
        MyLayouts->setWindowTitle(QApplication::translate("MyLayouts", "MyLayouts", 0));
    } // retranslateUi

};

namespace Ui {
    class MyLayouts: public Ui_MyLayouts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLAYOUTS_H
