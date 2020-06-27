/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changePassword
{
public:
    QLabel *titleLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *usernameLabel;
    QLabel *oldPasswordLabel;
    QLabel *newPasswordLabel;
    QLabel *newPasswordAgainLabel;
    QLineEdit *usernameInput;
    QLineEdit *oldPasswordInput;
    QLineEdit *newPasswordInput;
    QLineEdit *newPasswordAgainInput;
    QPushButton *backButton;
    QPushButton *confirmButton;
    QLabel *warningLabel;

    void setupUi(QWidget *changePassword)
    {
        if (changePassword->objectName().isEmpty())
            changePassword->setObjectName(QString::fromUtf8("changePassword"));
        changePassword->resize(800, 800);
        titleLabel = new QLabel(changePassword);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(330, 190, 141, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(36);
        titleLabel->setFont(font);
        gridLayoutWidget = new QWidget(changePassword);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(140, 380, 491, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(gridLayoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font1.setPointSize(18);
        usernameLabel->setFont(font1);
        usernameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(usernameLabel, 0, 0, 1, 1);

        oldPasswordLabel = new QLabel(gridLayoutWidget);
        oldPasswordLabel->setObjectName(QString::fromUtf8("oldPasswordLabel"));
        oldPasswordLabel->setFont(font1);
        oldPasswordLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(oldPasswordLabel, 1, 0, 1, 1);

        newPasswordLabel = new QLabel(gridLayoutWidget);
        newPasswordLabel->setObjectName(QString::fromUtf8("newPasswordLabel"));
        newPasswordLabel->setFont(font1);
        newPasswordLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(newPasswordLabel, 2, 0, 1, 1);

        newPasswordAgainLabel = new QLabel(gridLayoutWidget);
        newPasswordAgainLabel->setObjectName(QString::fromUtf8("newPasswordAgainLabel"));
        newPasswordAgainLabel->setFont(font1);
        newPasswordAgainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(newPasswordAgainLabel, 3, 0, 1, 1);

        usernameInput = new QLineEdit(gridLayoutWidget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        gridLayout->addWidget(usernameInput, 0, 1, 1, 1);

        oldPasswordInput = new QLineEdit(gridLayoutWidget);
        oldPasswordInput->setObjectName(QString::fromUtf8("oldPasswordInput"));
        oldPasswordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(oldPasswordInput, 1, 1, 1, 1);

        newPasswordInput = new QLineEdit(gridLayoutWidget);
        newPasswordInput->setObjectName(QString::fromUtf8("newPasswordInput"));
        newPasswordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPasswordInput, 2, 1, 1, 1);

        newPasswordAgainInput = new QLineEdit(gridLayoutWidget);
        newPasswordAgainInput->setObjectName(QString::fromUtf8("newPasswordAgainInput"));
        newPasswordAgainInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPasswordAgainInput, 3, 1, 1, 1);

        backButton = new QPushButton(changePassword);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(410, 630, 91, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font2.setPointSize(24);
        backButton->setFont(font2);
        confirmButton = new QPushButton(changePassword);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(670, 440, 91, 51));
        confirmButton->setFont(font2);
        warningLabel = new QLabel(changePassword);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setGeometry(QRect(290, 320, 241, 41));
        warningLabel->setFont(font2);
        warningLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(changePassword);

        QMetaObject::connectSlotsByName(changePassword);
    } // setupUi

    void retranslateUi(QWidget *changePassword)
    {
        changePassword->setWindowTitle(QCoreApplication::translate("changePassword", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("changePassword", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        usernameLabel->setText(QCoreApplication::translate("changePassword", "\347\224\250\346\210\267\345\220\215", nullptr));
        oldPasswordLabel->setText(QCoreApplication::translate("changePassword", "\346\227\247\345\257\206\347\240\201", nullptr));
        newPasswordLabel->setText(QCoreApplication::translate("changePassword", "\346\226\260\345\257\206\347\240\201", nullptr));
        newPasswordAgainLabel->setText(QCoreApplication::translate("changePassword", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        backButton->setText(QCoreApplication::translate("changePassword", "\350\277\224\345\233\236", nullptr));
        confirmButton->setText(QCoreApplication::translate("changePassword", "\347\241\256\345\256\232", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class changePassword: public Ui_changePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
