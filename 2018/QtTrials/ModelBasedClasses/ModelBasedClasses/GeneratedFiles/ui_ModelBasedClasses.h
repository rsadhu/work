/********************************************************************************
** Form generated from reading UI file 'ModelBasedClasses.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELBASEDCLASSES_H
#define UI_MODELBASEDCLASSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelBasedClassesClass
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnOk;

    void setupUi(QWidget *ModelBasedClassesClass)
    {
        if (ModelBasedClassesClass->objectName().isEmpty())
            ModelBasedClassesClass->setObjectName(QStringLiteral("ModelBasedClassesClass"));
        ModelBasedClassesClass->resize(176, 309);
        verticalLayout = new QVBoxLayout(ModelBasedClassesClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeView = new QTreeView(ModelBasedClassesClass);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCancel = new QPushButton(ModelBasedClassesClass);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnOk = new QPushButton(ModelBasedClassesClass);
        btnOk->setObjectName(QStringLiteral("btnOk"));

        horizontalLayout->addWidget(btnOk);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ModelBasedClassesClass);

        QMetaObject::connectSlotsByName(ModelBasedClassesClass);
    } // setupUi

    void retranslateUi(QWidget *ModelBasedClassesClass)
    {
        ModelBasedClassesClass->setWindowTitle(QApplication::translate("ModelBasedClassesClass", "ModelBasedClasses", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("ModelBasedClassesClass", "Ok", Q_NULLPTR));
        btnOk->setText(QApplication::translate("ModelBasedClassesClass", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModelBasedClassesClass: public Ui_ModelBasedClassesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELBASEDCLASSES_H
