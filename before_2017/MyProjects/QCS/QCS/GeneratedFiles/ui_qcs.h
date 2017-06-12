/********************************************************************************
** Form generated from reading UI file 'qcs.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCS_H
#define UI_QCS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCSClass
{
public:
    QGridLayout *gridLayout;
    QWidget *Txt;
    QGridLayout *gridLayout_2;
    QPushButton *showTxt;
    QWidget *Video;
    QGridLayout *gridLayout_4;
    QPushButton *showVid;
    QWidget *Web;
    QGridLayout *gridLayout_5;
    QPushButton *showWeb;
    QWidget *Img;
    QGridLayout *gridLayout_3;
    QPushButton *showImg;

    void setupUi(QWidget *QCSClass)
    {
        if (QCSClass->objectName().isEmpty())
            QCSClass->setObjectName(QStringLiteral("QCSClass"));
        QCSClass->resize(656, 560);
        gridLayout = new QGridLayout(QCSClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Txt = new QWidget(QCSClass);
        Txt->setObjectName(QStringLiteral("Txt"));
        gridLayout_2 = new QGridLayout(Txt);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        showTxt = new QPushButton(Txt);
        showTxt->setObjectName(QStringLiteral("showTxt"));

        gridLayout_2->addWidget(showTxt, 0, 0, 1, 1);


        gridLayout->addWidget(Txt, 0, 1, 1, 1);

        Video = new QWidget(QCSClass);
        Video->setObjectName(QStringLiteral("Video"));
        gridLayout_4 = new QGridLayout(Video);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        showVid = new QPushButton(Video);
        showVid->setObjectName(QStringLiteral("showVid"));

        gridLayout_4->addWidget(showVid, 0, 0, 1, 1);


        gridLayout->addWidget(Video, 1, 0, 1, 1);

        Web = new QWidget(QCSClass);
        Web->setObjectName(QStringLiteral("Web"));
        gridLayout_5 = new QGridLayout(Web);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        showWeb = new QPushButton(Web);
        showWeb->setObjectName(QStringLiteral("showWeb"));

        gridLayout_5->addWidget(showWeb, 0, 0, 1, 1);


        gridLayout->addWidget(Web, 1, 1, 1, 1);

        Img = new QWidget(QCSClass);
        Img->setObjectName(QStringLiteral("Img"));
        gridLayout_3 = new QGridLayout(Img);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        showImg = new QPushButton(Img);
        showImg->setObjectName(QStringLiteral("showImg"));

        gridLayout_3->addWidget(showImg, 0, 0, 1, 1);


        gridLayout->addWidget(Img, 0, 0, 1, 1);


        retranslateUi(QCSClass);

        QMetaObject::connectSlotsByName(QCSClass);
    } // setupUi

    void retranslateUi(QWidget *QCSClass)
    {
        QCSClass->setWindowTitle(QApplication::translate("QCSClass", "QCS", 0));
        showTxt->setText(QApplication::translate("QCSClass", "showText", 0));
        showVid->setText(QApplication::translate("QCSClass", "showVideo", 0));
        showWeb->setText(QApplication::translate("QCSClass", "showWeb", 0));
        showImg->setText(QApplication::translate("QCSClass", "showImg", 0));
    } // retranslateUi

};

namespace Ui {
    class QCSClass: public Ui_QCSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCS_H
