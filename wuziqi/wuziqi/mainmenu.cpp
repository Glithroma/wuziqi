#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QCloseEvent>
#include <QtDebug>
#include "mainwindow.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>

mainMenu::mainMenu(MainWindow *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainMenu),
    gui(NULL),
    game(NULL),
    repl(NULL)
{
    ui->setupUi(this);
    this->p=p;
    this->setWindowTitle("五子棋");
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(exitGame()));
    connect(ui->changeAccountButton, SIGNAL(clicked()), this, SLOT(changeAccount()));
    connect(ui->guideButton, SIGNAL(clicked()), this, SLOT(guide()));
    connect(ui->PVEButton, SIGNAL(clicked()), this, SLOT(PVEGame()));
    connect(ui->PVPButton, SIGNAL(clicked()), this, SLOT(PVPGame()));
    connect(ui->replayButton, SIGNAL(clicked()), this, SLOT(replay()));

    setTabOrder(ui->PVPButton, ui->PVEButton);
    setTabOrder(ui->PVEButton, ui->replayButton);
}

mainMenu::~mainMenu()
{
    delete gui;
    delete game;
    delete ui;
}

void mainMenu::closeEvent(QCloseEvent *event){
    //使在这个界面关闭窗口时，上层的mainwindow也能被关闭
    p->a->quit();
}

void mainMenu::exitGame(){
    p->a->quit();
}

void mainMenu::changeAccount(){
    this->hide();
    p->show();
}

void mainMenu::guide(){
    if(gui){
        delete gui;
        gui=NULL;
    }
    gui=new class guide(this);
    gui->show();
}

void mainMenu::PVEGame(){
    int playerColor;
    int ret = QMessageBox::question(this," "," 请选择棋子颜色 ", "白棋","黑棋");
    playerColor=ret;
    //ret为0代表白棋，ret为1代表黑棋
    if(game){
        delete game;
        game=NULL;
    }
    game=new Game(PVE, this);
    game->show();
    this->hide();
    if(playerColor == 0){
        game->AIMoveFirst();
    }
}

void mainMenu::PVPGame(){
    if(game){
        delete game;
        game=NULL;
    }
    game=new Game(PVP, this);
    game->show();
    this->hide();
}

void mainMenu::replay(){
    QString fileName = QFileDialog::getOpenFileName(this, "选择复盘文件", "data/replay");
    if(!fileName.isEmpty()){
        if(repl){
            delete repl;
            repl=NULL;
        }
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QDataStream fstream(&file);
        QString un;
        int i;
        for(i=fileName.size()-1; fileName[i] != '_'; i--){}
        un=fileName.right(fileName.size()-i-1);

        if(QString::compare(un, username) == 0){
            repl=new Replay(fileName, this);
            repl->show();
            this->hide();
        }else{
            QMessageBox::about(this, "打开失败", "无法查看其他用户的对局！");
        }
    }
}

void mainMenu::setUsername(QString &name){
    username=name;
}

QString& mainMenu::getUsername(){
    return username;
}
