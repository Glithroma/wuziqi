#include "replay.h"
#include "ui_replay.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QInputDialog>
#include "mainmenu.h"
#include "mainwindow.h"

static const int originX=50, originY=50, xInterval=50, yInterval=50, colNum=15, rowNum=15, interval=50,
        circleRadius=20;

Replay::Replay(QString fName, mainMenu *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replay),
    fileName(fName),
    file(fName),
    curColor(BLACK)
{
    this->p=p;
    ui->setupUi(this);
    memset(board, 0, sizeof(board));
    setWindowTitle("五子棋");

    file.open(QIODevice::ReadOnly);
    QDataStream fstream(&file);
    while(!file.atEnd()){
        qint32 x, y;
        fstream >> x >> y;
        fileMove.push_back(qint32Point(x, y));
    }

    connect(ui->nextMoveButton, SIGNAL(clicked()), this, SLOT(nextMove()));
    connect(ui->prevMoveButton, SIGNAL(clicked()), this, SLOT(prevMove()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->renameButton, SIGNAL(clicked()), this, SLOT(rename()));

    update();
}

Replay::~Replay()
{
    delete ui;
}

void Replay::switchColor(){
    curColor == WHITE ? curColor=BLACK : curColor=WHITE;
}

void Replay::closeEvent(QCloseEvent *event){
    p->p->a->quit();
}

void Replay::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿

    //绘制棋盘
    for (int i=0; i<colNum; i++) {
        painter.drawLine(originX+i*xInterval, originY, originX+i*xInterval, originY+(rowNum-1)*yInterval);
        painter.drawLine(originX, originY+i*yInterval, originX+(colNum-1)*xInterval, originY+i*yInterval);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    //绘制已有棋子
    for(int i=0; i<rowNum; i++){
        for(int j=0; j<colNum; j++){
            if(board[j][i] == WHITE){
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(originX+j*xInterval-circleRadius, originY+i*yInterval-circleRadius, 2*circleRadius, 2*circleRadius);
            }
            if(board[j][i] == BLACK){
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(originX+j*xInterval-circleRadius, originY+i*yInterval-circleRadius, 2*circleRadius, 2*circleRadius);
            }
        }
    }
    update();
}

void Replay::exit(){
    this->hide();
    p->show();
}

void Replay::nextMove(){
    if(!fileMove.empty()){
        qint32Point temp=fileMove.front();
        fileMove.pop_front();
        board[temp.x][temp.y]=curColor;
        switchColor();
        curMove.push_back(temp);
        update();
    }
}

void Replay::prevMove(){
    if(!curMove.empty()){
        qint32Point temp=curMove.last();
        curMove.pop_back();
        board[temp.x][temp.y]=EMPTY;
        switchColor();
        fileMove.push_front(temp);
        update();
    }
}

void Replay::rename(){
    bool confirm;
    QString newName=QInputDialog::getText(NULL, "复盘文件改名", "新名称：", QLineEdit::Normal, "",  &confirm);
    if(confirm){
        QString path="data/replay/";
        path.append(newName);
        path.append('_');
        path.append(p->getUsername());
        file.rename(path);
    }
}
