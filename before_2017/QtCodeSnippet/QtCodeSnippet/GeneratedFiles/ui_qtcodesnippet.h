/********************************************************************************
** Form generated from reading UI file 'qtcodesnippet.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCODESNIPPET_H
#define UI_QTCODESNIPPET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCodeSnippetClass
{
public:

    void setupUi(QWidget *QtCodeSnippetClass)
    {
        if (QtCodeSnippetClass->objectName().isEmpty())
            QtCodeSnippetClass->setObjectName(QStringLiteral("QtCodeSnippetClass"));
        QtCodeSnippetClass->resize(600, 400);

        retranslateUi(QtCodeSnippetClass);

        QMetaObject::connectSlotsByName(QtCodeSnippetClass);
    } // setupUi

    void retranslateUi(QWidget *QtCodeSnippetClass)
    {
        QtCodeSnippetClass->setWindowTitle(QApplication::translate("QtCodeSnippetClass", "QtCodeSnippet", 0));
    } // retranslateUi

};

namespace Ui {
    class QtCodeSnippetClass: public Ui_QtCodeSnippetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCODESNIPPET_H
