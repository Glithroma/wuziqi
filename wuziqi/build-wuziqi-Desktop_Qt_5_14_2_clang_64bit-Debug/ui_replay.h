/********************************************************************************
** Form generated from reading UI file 'replay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replay
{
public:
    QPushButton *renameButton;
    QPushButton *prevMoveButton;
    QPushButton *nextMoveButton;
    QPushButton *exitButton;

    void setupUi(QWidget *replay)
    {
        if (replay->objectName().isEmpty())
            replay->setObjectName(QString::fromUtf8("replay"));
        replay->resize(1000, 800);
        renameButton = new QPushButton(replay);
        renameButton->setObjectName(QString::fromUtf8("renameButton"));
        renameButton->setGeometry(QRect(820, 280, 111, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(24);
        renameButton->setFont(font);
        prevMoveButton = new QPushButton(replay);
        prevMoveButton->setObjectName(QString::fromUtf8("prevMoveButton"));
        prevMoveButton->setGeometry(QRect(820, 360, 111, 51));
        prevMoveButton->setFont(font);
        nextMoveButton = new QPushButton(replay);
        nextMoveButton->setObjectName(QString::fromUtf8("nextMoveButton"));
        nextMoveButton->setGeometry(QRect(820, 440, 111, 51));
        nextMoveButton->setFont(font);
        exitButton = new QPushButton(replay);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(820, 520, 111, 51));
        exitButton->setFont(font);

        retranslateUi(replay);

        QMetaObject::connectSlotsByName(replay);
    } // setupUi

    void retranslateUi(QWidget *replay)
    {
        replay->setWindowTitle(QCoreApplication::translate("replay", "Form", nullptr));
        renameButton->setText(QCoreApplication::translate("replay", "\346\226\207\344\273\266\346\224\271\345\220\215", nullptr));
        prevMoveButton->setText(QCoreApplication::translate("replay", "\344\270\212\344\270\200\346\255\245", nullptr));
        nextMoveButton->setText(QCoreApplication::translate("replay", "\344\270\213\344\270\200\346\255\245", nullptr));
        exitButton->setText(QCoreApplication::translate("replay", "\351\200\200\345\207\272\345\244\215\347\233\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replay: public Ui_replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
