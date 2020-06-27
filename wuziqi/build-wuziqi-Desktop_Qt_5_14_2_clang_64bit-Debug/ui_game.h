/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *retractButton;
    QPushButton *hintButton;
    QPushButton *exitButton;
    QPushButton *restartButton;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1000, 800);
        retractButton = new QPushButton(Game);
        retractButton->setObjectName(QString::fromUtf8("retractButton"));
        retractButton->setGeometry(QRect(820, 280, 111, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(24);
        retractButton->setFont(font);
        hintButton = new QPushButton(Game);
        hintButton->setObjectName(QString::fromUtf8("hintButton"));
        hintButton->setGeometry(QRect(820, 360, 111, 51));
        hintButton->setFont(font);
        exitButton = new QPushButton(Game);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(820, 520, 111, 51));
        exitButton->setFont(font);
        restartButton = new QPushButton(Game);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(820, 440, 111, 51));
        restartButton->setFont(font);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Form", nullptr));
        retractButton->setText(QCoreApplication::translate("Game", "\346\202\224\346\243\213", nullptr));
        hintButton->setText(QCoreApplication::translate("Game", "\346\217\220\347\244\272", nullptr));
        exitButton->setText(QCoreApplication::translate("Game", "\351\200\200\345\207\272", nullptr));
        restartButton->setText(QCoreApplication::translate("Game", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
