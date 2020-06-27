#include "registeraccount.h"
#include "ui_registeraccount.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registeraccount.h"
#include <QFile>
#include <QPushButton>
#include <iostream>
#include <QCloseEvent>
#include <QtDebug>
#include <QFileInfo>

registerAccount::registerAccount(MainWindow *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerAccount)
{
    ui->setupUi(this);
    this->setWindowTitle("五子棋");
    this->p=p;
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->warningLabel->setPalette(pe);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(closeRegisterInterface()));
    connect(ui->confirmButton, SIGNAL(clicked()), this, SLOT(registerPlayer()));
}

registerAccount::~registerAccount()
{
    delete ui;
}

void registerAccount::closeRegisterInterface(){
    this->hide();
    p->show();
}

void registerAccount::showInterface(){
    this->show();
}

void registerAccount::registerPlayer(){
    QString username, password, passwordAgain;
    QFile file("data/account/accountInfo");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "open failed";
    }
    QTextStream fstream(&file);

    username=ui->usernameInput->text();
    password=ui->passwordInput->text();
    passwordAgain=ui->passwordAgainInput->text();
    
    if(username.size() == 0 || password.size() == 0 || passwordAgain.size() == 0){
        ui->warningLabel->setText("下列数据不能为空！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        return;
    }
    if(QString::compare(password, passwordAgain) != 0){
        ui->warningLabel->setText("两次密码输入必须一致！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        return;
    }

    //检查用户名是否重复
    QString fileUsername;
    while (!file.atEnd()) {
        QByteArray fileLine=file.readLine();
        for (int i=1; fileLine[i-1] != '|'; i++) {
            if(fileLine[i] == '|'){
                fileLine.chop(fileLine.size()-i);
                fileUsername=QString(fileLine);
                break;
            }
        }
        if(QString::compare(fileUsername, username) == 0){
            ui->warningLabel->setText("用户名已存在！");
            ui->warningLabel->hide();
            ui->warningLabel->show();
            return;
        }
    }

    file.close();
    file.open(QIODevice::Append | QIODevice::Text);

    fstream << username << "|" << password << endl;
    ui->warningLabel->setText("创建成功！");
    ui->warningLabel->hide();
    ui->warningLabel->show();

    ui->usernameInput->clear();
    ui->usernameInput->hide();
    ui->usernameInput->show();
    ui->passwordInput->clear();
    ui->passwordInput->hide();
    ui->passwordInput->show();
    ui->passwordAgainInput->clear();
    ui->passwordAgainInput->hide();
    ui->passwordAgainInput->show();

    file.close();
}

void registerAccount::closeEvent(QCloseEvent *event){
    //使在这个界面关闭窗口时，上层的mainwindow也能被关闭
    p->a->quit();
}
