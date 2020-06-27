#include "changepassword.h"
#include "ui_changepassword.h"
#include <QCloseEvent>
#include "mainwindow.h"
#include <QtDebug>
#include <QFile>

changePassword::changePassword(MainWindow* par, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changePassword),
    p(par)
{
    ui->setupUi(this);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->warningLabel->setPalette(pe);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->confirmButton, SIGNAL(clicked()), this, SLOT(confirm()));
}

changePassword::~changePassword()
{
    delete ui;
}

void changePassword::closeEvent(QCloseEvent *event){
    //使在这个界面关闭窗口时，上层的mainwindow也能被关闭
    p->a->quit();
}

void changePassword::back(){
    ui->warningLabel->clear();
    ui->usernameInput->clear();
    ui->oldPasswordInput->clear();
    ui->newPasswordInput->clear();
    ui->newPasswordAgainInput->clear();
    this->close();
    p->show();
}

void changePassword::confirm(){
    QString username, oldPassword, newPassword, newPasswordAgain;
    QFile file("data/account/accountInfo");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    username=ui->usernameInput->text();
    oldPassword=ui->oldPasswordInput->text();
    newPassword=ui->newPasswordInput->text();
    newPasswordAgain=ui->newPasswordAgainInput->text();

    if(username.size() == 0 || newPassword.size() == 0 ||
            newPasswordAgain.size() == 0 || oldPassword.size() == 0){
        ui->warningLabel->setText("下列数据不能为空！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        file.close();
        return;
    }

    //读取文件中用户名
    bool accountExist=false;
    QString fileUsername, filePassword;
    int headofLinePos;
    while (!file.atEnd()) {
        headofLinePos=file.pos();
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
            accountExist=true;
            break;
        }
    }
    //不存在，输出提示信息
    if(!accountExist){
        ui->warningLabel->setText("账户不存在！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        file.close();
        return;
    }
    //存在，进行接下来的判断
    if(QString::compare(filePassword, oldPassword) != 0){
        ui->warningLabel->setText("密码错误！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        file.close();
        return;
    }

    if(QString::compare(newPassword, newPasswordAgain) != 0){
        ui->warningLabel->setText("两次输入密码不一致！");
        ui->warningLabel->hide();
        ui->warningLabel->show();
        file.close();
        return;
    }
    file.close();
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    file.seek(headofLinePos);

    QTextStream fstream(&file);
    fstream << username << "|" << newPassword << endl;

    ui->warningLabel->setText("修改成功！");
    ui->warningLabel->hide();
    ui->warningLabel->show();

    file.close();
}

void changePassword::showInterface(){
    p->hide();
    this->show();
}
