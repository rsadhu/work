/********************************************************************************
** Form generated from reading UI file 'codesnippet.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODESNIPPET_H
#define UI_CODESNIPPET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeSnippetClass
{
public:

    void setupUi(QWidget *CodeSnippetClass)
    {
        if (CodeSnippetClass->objectName().isEmpty())
            CodeSnippetClass->setObjectName(QStringLiteral("CodeSnippetClass"));
        CodeSnippetClass->resize(600, 400);

        retranslateUi(CodeSnippetClass);

        QMetaObject::connectSlotsByName(CodeSnippetClass);
    } // setupUi

    void retranslateUi(QWidget *CodeSnippetClass)
    {
        CodeSnippetClass->setWindowTitle(QApplication::translate("CodeSnippetClass", "CodeSnippet", 0));
    } // retranslateUi

};

namespace Ui {
    class CodeSnippetClass: public Ui_CodeSnippetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODESNIPPET_H
