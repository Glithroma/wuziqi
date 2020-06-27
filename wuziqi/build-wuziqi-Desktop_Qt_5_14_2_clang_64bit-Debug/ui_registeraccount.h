/********************************************************************************
** Form generated from reading UI file 'registeraccount.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERACCOUNT_H
#define UI_REGISTERACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerAccount
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *passwordAgainLabel;
    QLabel *passwordLabel;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QLineEdit *passwordAgainInput;
    QPushButton *confirmButton;
    QPushButton *backButton;
    QLabel *interfaceNameLabel;
    QLabel *warningLabel;

    void setupUi(QWidget *registerAccount)
    {
        if (registerAccount->objectName().isEmpty())
            registerAccount->setObjectName(QString::fromUtf8("registerAccount"));
        registerAccount->resize(800, 800);
        gridLayoutWidget = new QWidget(registerAccount);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 300, 491, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordAgainLabel = new QLabel(gridLayoutWidget);
        passwordAgainLabel->setObjectName(QString::fromUtf8("passwordAgainLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(24);
        passwordAgainLabel->setFont(font);

        gridLayout->addWidget(passwordAgainLabel, 2, 0, 1, 1);

        passwordLabel = new QLabel(gridLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font);
        passwordLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        usernameLabel = new QLabel(gridLayoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setFont(font);
        usernameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(usernameLabel, 0, 0, 1, 1);

        usernameInput = new QLineEdit(gridLayoutWidget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));
        usernameInput->setMaxLength(20);

        gridLayout->addWidget(usernameInput, 0, 1, 1, 1);

        passwordInput = new QLineEdit(gridLayoutWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setMaxLength(20);
        passwordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordInput, 1, 1, 1, 1);

        passwordAgainInput = new QLineEdit(gridLayoutWidget);
        passwordAgainInput->setObjectName(QString::fromUtf8("passwordAgainInput"));
        passwordAgainInput->setMaxLength(20);
        passwordAgainInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordAgainInput, 2, 1, 1, 1);

        confirmButton = new QPushButton(registerAccount);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(620, 360, 112, 61));
        confirmButton->setFont(font);
        backButton = new QPushButton(registerAccount);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(350, 540, 112, 61));
        backButton->setFont(font);
        interfaceNameLabel = new QLabel(registerAccount);
        interfaceNameLabel->setObjectName(QString::fromUtf8("interfaceNameLabel"));
        interfaceNameLabel->setGeometry(QRect(310, 160, 231, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font1.setPointSize(36);
        interfaceNameLabel->setFont(font1);
        warningLabel = new QLabel(registerAccount);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setGeometry(QRect(310, 260, 181, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kaiti SC"));
        font2.setPointSize(22);
        warningLabel->setFont(font2);

        retranslateUi(registerAccount);

        QMetaObject::connectSlotsByName(registerAccount);
    } // setupUi

    void retranslateUi(QWidget *registerAccount)
    {
        registerAccount->setWindowTitle(QCoreApplication::translate("registerAccount", "Form", nullptr));
        passwordAgainLabel->setText(QCoreApplication::translate("registerAccount", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        passwordLabel->setText(QCoreApplication::translate("registerAccount", "\345\257\206\347\240\201", nullptr));
        usernameLabel->setText(QCoreApplication::translate("registerAccount", "\347\224\250\346\210\267\345\220\215", nullptr));
        confirmButton->setText(QCoreApplication::translate("registerAccount", "\347\241\256\345\256\232", nullptr));
        backButton->setText(QCoreApplication::translate("registerAccount", "\350\277\224\345\233\236", nullptr));
        interfaceNameLabel->setText(QCoreApplication::translate("registerAccount", "\346\263\250\345\206\214\346\226\260\350\264\246\345\217\267", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registerAccount: public Ui_registerAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERACCOUNT_H
