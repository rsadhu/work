/********************************************************************************
** Form generated from reading UI file 'LoginClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINCLIENT_H
#define UI_LOGINCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lePassword;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(174, 140);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        leUsername = new QLineEdit(Login);
        leUsername->setObjectName(QStringLiteral("leUsername"));

        horizontalLayout->addWidget(leUsername);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lePassword = new QLineEdit(Login);
        lePassword->setObjectName(QStringLiteral("lePassword"));

        horizontalLayout_2->addWidget(lePassword);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Login);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(Login);
        QObject::connect(buttonBox, SIGNAL(accepted()), Login, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Login, SLOT(reject()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "UserName", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINCLIENT_H
