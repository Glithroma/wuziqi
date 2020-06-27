/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QLabel *gameNameLabel;
    QPushButton *PVPButton;
    QPushButton *replayButton;
    QPushButton *PVEButton;
    QPushButton *guideButton;
    QPushButton *quitButton;
    QPushButton *changeAccountButton;

    void setupUi(QWidget *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->resize(800, 800);
        gameNameLabel = new QLabel(mainMenu);
        gameNameLabel->setObjectName(QString::fromUtf8("gameNameLabel"));
        gameNameLabel->setGeometry(QRect(325, 150, 150, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\303\216\303\222"));
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        gameNameLabel->setFont(font);
        PVPButton = new QPushButton(mainMenu);
        PVPButton->setObjectName(QString::fromUtf8("PVPButton"));
        PVPButton->setGeometry(QRect(350, 280, 121, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font1.setPointSize(24);
        PVPButton->setFont(font1);
        replayButton = new QPushButton(mainMenu);
        replayButton->setObjectName(QString::fromUtf8("replayButton"));
        replayButton->setGeometry(QRect(350, 420, 121, 51));
        replayButton->setFont(font1);
        PVEButton = new QPushButton(mainMenu);
        PVEButton->setObjectName(QString::fromUtf8("PVEButton"));
        PVEButton->setGeometry(QRect(350, 350, 121, 51));
        PVEButton->setFont(font1);
        guideButton = new QPushButton(mainMenu);
        guideButton->setObjectName(QString::fromUtf8("guideButton"));
        guideButton->setGeometry(QRect(350, 490, 121, 51));
        guideButton->setFont(font1);
        quitButton = new QPushButton(mainMenu);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(350, 630, 121, 51));
        quitButton->setFont(font1);
        changeAccountButton = new QPushButton(mainMenu);
        changeAccountButton->setObjectName(QString::fromUtf8("changeAccountButton"));
        changeAccountButton->setGeometry(QRect(350, 560, 121, 51));
        changeAccountButton->setFont(font1);

        retranslateUi(mainMenu);

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QWidget *mainMenu)
    {
        mainMenu->setWindowTitle(QCoreApplication::translate("mainMenu", "Form", nullptr));
        gameNameLabel->setText(QCoreApplication::translate("mainMenu", "\344\272\224\345\255\220\346\243\213", nullptr));
        PVPButton->setText(QCoreApplication::translate("mainMenu", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        replayButton->setText(QCoreApplication::translate("mainMenu", "\345\244\215\347\233\230", nullptr));
        PVEButton->setText(QCoreApplication::translate("mainMenu", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        guideButton->setText(QCoreApplication::translate("mainMenu", "\346\270\270\346\210\217\350\257\264\346\230\216", nullptr));
        quitButton->setText(QCoreApplication::translate("mainMenu", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        changeAccountButton->setText(QCoreApplication::translate("mainMenu", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
