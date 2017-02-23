/********************************************************************************
** Form generated from reading UI file 'dictionary.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARY_H
#define UI_DICTIONARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dictionaryClass
{
public:

    void setupUi(QWidget *dictionaryClass)
    {
        if (dictionaryClass->objectName().isEmpty())
            dictionaryClass->setObjectName(QStringLiteral("dictionaryClass"));
        dictionaryClass->resize(600, 400);

        retranslateUi(dictionaryClass);

        QMetaObject::connectSlotsByName(dictionaryClass);
    } // setupUi

    void retranslateUi(QWidget *dictionaryClass)
    {
        dictionaryClass->setWindowTitle(QApplication::translate("dictionaryClass", "dictionary", 0));
    } // retranslateUi

};

namespace Ui {
    class dictionaryClass: public Ui_dictionaryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
