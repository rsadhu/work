/********************************************************************************
** Form generated from reading UI file 'myvideoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYVIDEOPLAYER_H
#define UI_MYVIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyVideoPlayer
{
public:

    void setupUi(QWidget *MyVideoPlayer)
    {
        if (MyVideoPlayer->objectName().isEmpty())
            MyVideoPlayer->setObjectName(QStringLiteral("MyVideoPlayer"));
        MyVideoPlayer->resize(400, 300);

        retranslateUi(MyVideoPlayer);

        QMetaObject::connectSlotsByName(MyVideoPlayer);
    } // setupUi

    void retranslateUi(QWidget *MyVideoPlayer)
    {
        MyVideoPlayer->setWindowTitle(QApplication::translate("MyVideoPlayer", "MyVideoPlayer", 0));
    } // retranslateUi

};

namespace Ui {
    class MyVideoPlayer: public Ui_MyVideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYVIDEOPLAYER_H
