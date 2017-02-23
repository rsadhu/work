/********************************************************************************
** Form generated from reading UI file 'rtspplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTSPPLAYER_H
#define UI_RTSPPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rtspPlayerClass
{
public:

    void setupUi(QWidget *rtspPlayerClass)
    {
        if (rtspPlayerClass->objectName().isEmpty())
            rtspPlayerClass->setObjectName(QStringLiteral("rtspPlayerClass"));
        rtspPlayerClass->resize(600, 400);

        retranslateUi(rtspPlayerClass);

        QMetaObject::connectSlotsByName(rtspPlayerClass);
    } // setupUi

    void retranslateUi(QWidget *rtspPlayerClass)
    {
        rtspPlayerClass->setWindowTitle(QApplication::translate("rtspPlayerClass", "rtspPlayer", 0));
    } // retranslateUi

};

namespace Ui {
    class rtspPlayerClass: public Ui_rtspPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTSPPLAYER_H
