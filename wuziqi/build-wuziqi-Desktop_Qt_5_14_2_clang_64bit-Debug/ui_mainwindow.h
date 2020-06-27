/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *usernameTextLabel;
    QLabel *passwordTextLabel;
    QLineEdit *passwordInput;
    QLineEdit *usernameInput;
    QLabel *gameNameLabel;
    QLabel *warningLabel;
    QPushButton *changePasswordButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(630, 470, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(24);
        loginButton->setFont(font);
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(260, 610, 101, 51));
        registerButton->setFont(font);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(220, 440, 361, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usernameTextLabel = new QLabel(gridLayoutWidget);
        usernameTextLabel->setObjectName(QString::fromUtf8("usernameTextLabel"));
        usernameTextLabel->setFont(font);

        gridLayout->addWidget(usernameTextLabel, 0, 0, 1, 1);

        passwordTextLabel = new QLabel(gridLayoutWidget);
        passwordTextLabel->setObjectName(QString::fromUtf8("passwordTextLabel"));
        passwordTextLabel->setFont(font);
        passwordTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(passwordTextLabel, 1, 0, 1, 1);

        passwordInput = new QLineEdit(gridLayoutWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setMaxLength(20);
        passwordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordInput, 1, 1, 1, 1);

        usernameInput = new QLineEdit(gridLayoutWidget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));
        usernameInput->setInputMethodHints(Qt::ImhNone);
        usernameInput->setMaxLength(20);
        usernameInput->setClearButtonEnabled(false);

        gridLayout->addWidget(usernameInput, 0, 1, 1, 1);

        gameNameLabel = new QLabel(centralwidget);
        gameNameLabel->setObjectName(QString::fromUtf8("gameNameLabel"));
        gameNameLabel->setGeometry(QRect(325, 150, 170, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\303\216\303\222"));
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setWeight(75);
        gameNameLabel->setFont(font1);
        warningLabel = new QLabel(centralwidget);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setGeometry(QRect(220, 395, 361, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font2.setPointSize(36);
        warningLabel->setFont(font2);
        warningLabel->setAlignment(Qt::AlignCenter);
        changePasswordButton = new QPushButton(centralwidget);
        changePasswordButton->setObjectName(QString::fromUtf8("changePasswordButton"));
        changePasswordButton->setGeometry(QRect(430, 610, 131, 51));
        changePasswordButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\351\231\206", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        usernameTextLabel->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordTextLabel->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        usernameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        gameNameLabel->setText(QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
        warningLabel->setText(QString());
        changePasswordButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
