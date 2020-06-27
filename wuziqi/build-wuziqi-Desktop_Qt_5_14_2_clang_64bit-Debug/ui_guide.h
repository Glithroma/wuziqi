/********************************************************************************
** Form generated from reading UI file 'guide.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDE_H
#define UI_GUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guide
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QWidget *guide)
    {
        if (guide->objectName().isEmpty())
            guide->setObjectName(QString::fromUtf8("guide"));
        guide->resize(600, 600);
        verticalLayoutWidget = new QWidget(guide);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 240, 470, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font.setPointSize(18);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label = new QLabel(guide);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(225, 130, 151, 46));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font1.setPointSize(36);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        backButton = new QPushButton(guide);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(245, 430, 111, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AaJHNDMCC (Non-Commercial Use)"));
        font2.setPointSize(24);
        backButton->setFont(font2);

        retranslateUi(guide);

        QMetaObject::connectSlotsByName(guide);
    } // setupUi

    void retranslateUi(QWidget *guide)
    {
        guide->setWindowTitle(QCoreApplication::translate("guide", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("guide", "\344\272\224\345\255\220\346\243\213\346\230\257\345\205\250\345\233\275\346\231\272\345\212\233\350\277\220\345\212\250\344\274\232\347\253\236\346\212\200\351\241\271\347\233\256\344\271\213\344\270\200\357\274\214\346\230\257\344\270\200\347\247\215\344\270\244\344\272\272\345\257\271\345\274\210\347\232\204", nullptr));
        label_3->setText(QCoreApplication::translate("guide", "\347\272\257\347\255\226\347\225\245\345\236\213\346\243\213\347\261\273\346\270\270\346\210\217\343\200\202\351\200\232\345\270\270\345\217\214\346\226\271\345\210\206\345\210\253\344\275\277\347\224\250\351\273\221\347\231\275\344\270\244\350\211\262\347\232\204\346\243\213\345\255\220\357\274\214", nullptr));
        label_4->setText(QCoreApplication::translate("guide", "\344\270\213\345\234\250\346\243\213\347\233\230\347\233\264\347\272\277\344\270\216\346\250\252\347\272\277\347\232\204\344\272\244\345\217\211\347\202\271\344\270\212\357\274\214\345\205\210\345\275\242\346\210\220\344\272\224\345\255\220\350\277\236\347\272\277\350\200\205\350\216\267\350\203\234\343\200\202", nullptr));
        label->setText(QCoreApplication::translate("guide", "\350\247\204\345\210\231\344\273\213\347\273\215", nullptr));
        backButton->setText(QCoreApplication::translate("guide", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guide: public Ui_guide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_H
