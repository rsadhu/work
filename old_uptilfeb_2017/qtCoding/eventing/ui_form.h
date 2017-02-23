/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(676, 574);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(Form);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 3, 2);

        graphicsView_4 = new QGraphicsView(Form);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));

        gridLayout->addWidget(graphicsView_4, 0, 2, 1, 1);

        graphicsView_5 = new QGraphicsView(Form);
        graphicsView_5->setObjectName(QStringLiteral("graphicsView_5"));

        gridLayout->addWidget(graphicsView_5, 1, 2, 1, 1);

        graphicsView_6 = new QGraphicsView(Form);
        graphicsView_6->setObjectName(QStringLiteral("graphicsView_6"));

        gridLayout->addWidget(graphicsView_6, 2, 2, 1, 1);

        graphicsView_2 = new QGraphicsView(Form);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 3, 0, 1, 1);

        graphicsView_3 = new QGraphicsView(Form);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));

        gridLayout->addWidget(graphicsView_3, 3, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
