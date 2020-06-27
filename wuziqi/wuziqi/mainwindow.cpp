#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QtDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , registerAccountInterface(this)
    , menu(this)
    , change(this)
{
    ui->setupUi(this);
    this->setMinimumSize(800, 800);
    this->setMaximumSize(800, 800);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->warningLabel->setPalette(pe);

    //设置默认焦点和焦点顺序
    ui->usernameInput->setFocus();
    setTabOrder(ui->usernameInput, ui->passwordInput);
    setTabOrder(ui->passwordInput, ui->loginButton);
    //连接用户名/密码输入框与登陆按钮，使得focus在这两个对象上时按回车的效果与按登陆按钮相同
    connect(ui->passwordInput, SIGNAL(returnPressed()), ui->loginButton, SIGNAL(clicked()));
    connect(ui->usernameInput, SIGNAL(returnPressed()), ui->loginButton, SIGNAL(clicked()));
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(login()));
    connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(registerAccount()));
    connect(ui->changePasswordButton, SIGNAL(clicked()), this, SLOT(changePassword()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login(){
    QString username=ui->usernameInput->text(), password=ui->passwordInput->text();

    if(username.size() == 0 || password.size() == 0){
        ui->warningLabel->setText("请输入账号密码！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        return;
    }

    QFile file("data/account/accountInfo");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString fileUsername, filePassword;
    while (!file.atEnd()) {
        QByteArray fileLine=file.readLine();
        for (int i=1; fileLine[i-1] != '|'; i++) {
            if(fileLine[i] == '|'){
                fileUsername=QString(fileLine.left(i));
                filePassword=QString(fileLine.right(fileLine.size()-i-1));
                filePassword.remove(filePassword.size()-1, 1);
                break;
            }
        }
        if(QString::compare(fileUsername, username) == 0){
            if(QString::compare(filePassword, password) == 0){
                //登陆成功
                ui->usernameInput->clear();
                ui->passwordInput->clear();
                menu.setUsername(username);
                this->hide();
                menu.show();
            }else{
                ui->warningLabel->setText("密码错误！");
                ui->warningLabel->hide();
                ui->warningLabel->show();
            }
            return;
        }
    }

    ui->warningLabel->setText("无账号！");
    ui->warningLabel->hide();
    ui->warningLabel->show();
}

void MainWindow::registerAccount(){
    this->hide();
    registerAccountInterface.showInterface();
}

void MainWindow::changePassword(){
    change.showInterface();
}
