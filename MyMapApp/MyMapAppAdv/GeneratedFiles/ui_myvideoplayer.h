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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyVideoPlayer
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyVideoPlayer)
    {
        if (MyVideoPlayer->objectName().isEmpty())
            MyVideoPlayer->setObjectName(QStringLiteral("MyVideoPlayer"));
        MyVideoPlayer->resize(617, 507);
        verticalLayout_2 = new QVBoxLayout(MyVideoPlayer);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(MyVideoPlayer);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(MyVideoPlayer);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MyVideoPlayer);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MyVideoPlayer);

        QMetaObject::connectSlotsByName(MyVideoPlayer);
    } // setupUi

    void retranslateUi(QWidget *MyVideoPlayer)
    {
        MyVideoPlayer->setWindowTitle(QApplication::translate("MyVideoPlayer", "MyVideoPlayer", 0));
        pushButton->setText(QApplication::translate("MyVideoPlayer", "Play", 0));
        pushButton_2->setText(QApplication::translate("MyVideoPlayer", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MyVideoPlayer: public Ui_MyVideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYVIDEOPLAYER_H
