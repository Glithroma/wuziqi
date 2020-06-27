#include "game.h"
#include "ui_game.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QTimer>
#include <QFile>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDateTime>
#include "mainmenu.h"
#include "mainwindow.h"
#include <iostream>

static const int originX=50, originY=50, xInterval=50, yInterval=50, colNum=15, rowNum=15, interval=50,
        circleRadius=20;

Game::Game(int gameMode, mainMenu *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game),
    gameFlag(gameMode),
    pieceNum(0),
    gameStatus(PLAYING),
    curColor(BLACK)
{
    this->p=p;
    ui->setupUi(this);

    setMouseTracking(true); //使mouseMoveEvent在鼠标左键没按下时也能追踪鼠标轨迹
    memset(board, 0, sizeof(board));
    setWindowTitle("五子棋");

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->hintButton, SIGNAL(clicked()), this, SLOT(hint()));
    connect(ui->retractButton, SIGNAL(clicked()), this, SLOT(retract()));

    repaint();
}

Game::~Game()
{
    delete ui;
}

void Game::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿

    //绘制棋盘
    for (int i=0; i<colNum; i++) {
        painter.drawLine(originX+i*xInterval, originY, originX+i*xInterval, originY+(rowNum-1)*yInterval);
        painter.drawLine(originX, originY+i*yInterval, originX+(colNum-1)*xInterval, originY+i*yInterval);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    //绘制落子标记
    const int blockSize=10; //落子标记大小
    if(curCol >= 0 && curRow >= 0
            &&curCol < colNum && curRow < rowNum
            && board[curCol][curRow] == 0){
        if(curColor == WHITE){
            brush.setColor(Qt::white);
        }else{
            brush.setColor(Qt::black);
        }
        painter.setBrush(brush);
        painter.drawRect(originX+curCol*xInterval-blockSize/2, originY+curRow*yInterval-blockSize/2, blockSize, blockSize);
    }

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

    remindLastMove();
}

void Game::mouseMoveEvent(QMouseEvent *event){
    int x, y;
    x=event->x();
    y=event->y();

    //当鼠标位于每个交叉点附近正负interval/3的区域内，可以绘制落子标记。
    //并且在此区域内点击时，可以成功落子。
    curCol=-1;
    curRow=-1;
    if(x > originX-interval/3 && x < originX+xInterval*(colNum-1)+interval/3 &&
            y > originY-interval/3 && y < originY+yInterval*(rowNum-1)+interval/3 &&
            gameStatus == PLAYING){
        //确定鼠标所在的交点
        for(int i=0; i<colNum; i++){
            if(originX+i*xInterval-interval/3 < x && x < originX+i*xInterval+interval/3){
                curCol=i;
                break;
            }
        }
        for(int i=0; i<rowNum; i++){
            if(originY+i*yInterval-interval/3 < y && y < originY+i*yInterval+interval/3){
                curRow=i;
                break;
            }
        }
    }
    //此时，如果curCol和curRow为-1，则鼠标目前不在落子区域

    //重新绘制棋盘
    repaint();
}

void Game::mouseReleaseEvent(QMouseEvent *event){
    if(gameStatus == PLAYING){
        if(curCol != -1 && curRow != -1 && board[curCol][curRow] == 0){
            board[curCol][curRow]=curColor;
            move.push_back(Point(curCol, curRow));
            pieceNum++;
            repaint();
            checkWin(curCol, curRow);
            checkDraw();
            switchColor();
            if(gameFlag == PVE && gameStatus == PLAYING){
                AIAct();
            }
        }
    }
    update();
}

void Game::switchColor(){
    curColor == WHITE ? curColor=BLACK : curColor=WHITE;
}

int Game::oppositeColor(int color){
    if(color == WHITE)
        return BLACK;
    if(color == BLACK)
        return WHITE;
    return EMPTY;
}

void Game::closeEvent(QCloseEvent *event){
    p->p->a->quit();
}

void Game::exit(){
    this->hide();
    p->show();
}

bool Game::checkWin(int x, int y){
    int num=1, winFlag=0;
    const int color=board[x][y];

    //横向检测
    for(int i=1; i<5 && x+i < colNum; i++){
        //横向正向
        if(board[x+i][y] == color)
            num++;
        else
            break;
    }
    for(int i=1; i<5 && x-i >= 0; i++){
        //横向反向
        if(board[x-i][y] == color)
            num++;
        else
            break;
    }
    if(num >= 5){
        winFlag=1;
    }else{
        num=1;
    }

    //竖向检测
    for(int i=1; i<5 && y+i <rowNum; i++){
        //竖向正向
        if(board[x][y+i] == color)
            num++;
        else
            break;
    }
    for(int i=1; i<5 && y-i <rowNum; i++){
        //竖向反向
        if(board[x][y-i] == color)
            num++;
        else
            break;
    }
    if(num >= 5){
        winFlag=1;
    }else{
        num=1;
    }

    //左上->右下方向
    for(int i=1; i<5 && x-i >= 0 && y-i >= 0; i++){
        //左上方向
        if(board[x-i][y-i] == color)
            num++;
        else
            break;
    }
    for(int i=1; i<5 && x+i < colNum && y+i < rowNum; i++){
        //右下方向
        if(board[x+i][y+i] == color)
            num++;
        else
            break;
    }
    if(num >= 5){
        winFlag=1;
    }else{
        num=1;
    }
    //右上->左下方向
    for(int i=1; i<5 && x+i < colNum && y-i >= 0; i++){
        //右上方向
        if(board[x+i][y-i] == color)
            num++;
        else
            break;
    }
    for(int i=1; i<5 && x-i >= 0 && y+i < rowNum; i++){
        //左下方向
        if(board[x-i][y+i] == color)
            num++;
        else
            break;
    }
    if(num >= 5){
        winFlag=1;
    }

    if(winFlag){
        gameStatus=END;
        QMessageBox::information(this, " ", "Game Over!");
        createReplayFile();
        return true;
    }else{
        return false;
    }
}

bool Game::checkDraw(){
    if(pieceNum == 225){
        QMessageBox::information(this, " ", "平局!");
        gameStatus=END;
        createReplayFile();
        return true;
    }
    else
        return false;
}

void Game::AIAct(){
    int bestX, bestY, maxScore=0;

    for(int i=0; i<rowNum; i++){
        for(int j=0; j<colNum; j++){
            if(board[j][i] == EMPTY){
                int score=evaluate(j, i, curColor);
                if(score > maxScore){
                    maxScore=score;
                    bestX=j;
                    bestY=i;
                }
            }
        }
    }

    //enda:

    repaint();
    board[bestX][bestY]=curColor;
    move.push_back(Point(bestX, bestY));
    switchColor();
    pieceNum++;
    checkWin(bestX, bestY);
    checkDraw();
}

void Game::getNeighbor(QVector<Point> &v){
    //获取棋盘上所有与棋子距离1的空点，为接下来博弈树计算减少点位。
    for(int i=0; i<colNum; i++){
        for(int j=0; j<rowNum; j++){
            if(board[i][j] == EMPTY){
                for(int dx=-1; dx<=1; dx++){
                    for(int dy=-1; dy<=1; dy++){
                        if(dx != 0 || dy != 0){
                            if(i+dx >= 0 && i+dx < colNum
                                    && j+dy >= 0 && j+dy < rowNum
                                    && board[i+dx][j+dy] != EMPTY){
                                v.push_back(Point(i, j));
                                goto nextPoint;
                            }
                        }
                    }
                }
                nextPoint:;
            }
        }
    }
}

int Game::findBestPoint(QVector<Point> neighborPoint, int beta, int color, int count){

    {
        //这部分代码粘贴到AIAct函数里就好

        QVector<Point> neighborPoint;
        int bestScore=INF;
        Point bestPoint;
        getNeighbor(neighborPoint);
        if(neighborPoint.empty()){
            //bestX=bestY=8;
            //goto enda;
        }
        //test code
        for(int i=0; i<neighborPoint.size(); i++){
            Point temp=neighborPoint.last();
            neighborPoint.pop_back();
            board[temp.x][temp.y]=curColor;

            int score=findBestPoint(neighborPoint, bestScore, oppositeColor(curColor), 3);
            if(bestScore > score){
                bestScore=score;
                bestPoint=temp;
            }

            neighborPoint.push_front(temp);
            board[temp.x][temp.y]=EMPTY;
        }
        //bestX=bestPoint.x;
        //bestY=bestPoint.y;
    }



    //如果到达底层
    if(count == 0){
        int maxScore=0;
        for(int i=0; i<neighborPoint.size(); i++){
            int score=evaluate(neighborPoint[i].x, neighborPoint[i].y, color);
            if(maxScore < score){
                maxScore=score;
            }
        }
        return maxScore;
    }
    
    //计算博弈树
    const int MAX=0, MIN=1;
    int alpha, flag;
    color == curColor? flag=MAX: flag=MIN;
    flag == MAX? alpha=-INF: alpha=INF;
    //if(count == 1)  alpha=-INF;
    
    for(int i=0; i<neighborPoint.size(); i++){
        Point temp=neighborPoint.last();
        neighborPoint.pop_back();
        board[temp.x][temp.y]=color;
        QVector<Point> newNeighborPoint;
        getNeighbor(newNeighborPoint);
        
        int score=findBestPoint(newNeighborPoint, alpha, oppositeColor(color), count-1);
        //if(count != 1){
            if(flag == MAX && alpha < score){
                alpha=score;
            }
            if(flag == MIN && score < alpha){
                alpha=score;
            }
        //}else{
        //    if(alpha < score)
        //        alpha=score;
        //}
        if((flag == MAX && beta < alpha) ||
                (flag == MIN && alpha < beta)){
            neighborPoint.push_front(temp);
            board[temp.x][temp.y]=EMPTY;
            qDebug() << "here";
            return alpha;
        }
        
        neighborPoint.push_front(temp);
        board[temp.x][temp.y]=EMPTY;
    }
    
    return alpha;
}

int Game::evaluate(int x, int y, int color){
    int score=0;
    int enemyPieceNum=0, emptyNum=0, friendPieceNum=0;
    for(int dy=-1; dy<=1; dy++){
        for(int dx=-1; dx<=1; dx++){
            emptyNum=0; friendPieceNum=0; enemyPieceNum=0;
            //除去原点，即正在评估的这个点
            if(dx != 0 || dy != 0){
                //评估防守情况
                //正向
                for(int i=1; i<5; i++){
                    if(x+i*dx >= 0 && y+i*dy >= 0 &&
                            x+i*dx < colNum && y+i*dy < rowNum &&
                            board[x+i*dx][y+i*dy] == oppositeColor(color)){
                        //如果这一点是对方棋子
                        enemyPieceNum++;
                    }else if(board[x+i*dx][y+i*dy] == EMPTY){
                        //如果这一点是空
                        emptyNum++;
                        break;
                    }else{
                        //如果到了边界或者这一点是友方棋子
                        break;
                    }
                }
                //反向
                for(int i=1; i<5; i++){
                    if(x-i*dx >= 0 && y-i*dy >= 0 &&
                            x-i*dx < colNum && y-i*dy < rowNum &&
                            board[x-i*dx][y-i*dy] == oppositeColor(color)){
                        //如果这一点是对方棋子
                        enemyPieceNum++;
                    }else if(board[x-i*dx][y-i*dy] == EMPTY){
                        //如果这一点是空
                        emptyNum++;
                        break;
                    }else{
                        //如果到了边界或者这一点是友方棋子
                        break;
                    }
                }

                //*=评估位置 o=敌方棋子或边界 x=友方棋子 #=空白
                // 空位数不一样，优先级不一样
                if (enemyPieceNum == 1){                      // 杀二
                    if (emptyNum == 1)
                        score+=100;
                    else if (emptyNum == 2)
                        score+=500;
                }
                else if (enemyPieceNum == 2){                 // 杀三
                    if (emptyNum == 1)
                        //  #*xxo   #x*xo   的情况
                        score+=1000;
                    else if (emptyNum == 2)
                        //  #*xx#   的情况
                        score+=2000;
                }
                else if (enemyPieceNum == 3){                 // 杀四
                    if (emptyNum == 1)
                        //  #*xxxo  #x*xxo  等情况
                        score+=2500;
                    else if (emptyNum == 2)
                        //  #*xxx#  等情况
                        score+=7500;
                }
                else if (enemyPieceNum == 4){                 // 杀五
                    //此时无所谓emptyNum是1还是2了，是2必败，只需要把优先级调到仅次于直接胜利的最高就好了
                    score+=100000;
                }



                //评估进攻情况
                emptyNum = 0;
                //正向
                for(int i=1; i<5; i++){
                    if(x+i*dx >= 0 && y+i*dy >= 0 &&
                            x+i*dx < colNum && y+i*dy < rowNum &&
                            board[x+i*dx][y+i*dy] == color){
                        //如果这一点是友方棋子
                        friendPieceNum++;
                    }else if(board[x+i*dx][y+i*dy] == EMPTY){
                        //如果这一点是空
                        emptyNum++;
                        break;
                    }else{
                        //如果到了边界或者这一点是对方棋子
                        break;
                    }
                }
                //反向
                for(int i=1; i<5; i++){
                    if(x-i*dx >= 0 && y-i*dy >= 0 &&
                            x-i*dx < colNum && y-i*dy < rowNum &&
                            board[x-i*dx][y-i*dy] == color){
                        //如果这一点是友方棋子
                        friendPieceNum++;
                    }else if(board[x-i*dx][y-i*dy] == EMPTY){
                        //如果这一点是空
                        emptyNum++;
                        break;
                    }else{
                        //如果到了边界或者这一点是对方棋子
                        break;
                    }
                }

                if (friendPieceNum == 0)                      // 普通下子
                    score += 0;
                else if (friendPieceNum == 1){
                    if(emptyNum == 1)               //死二
                        score += 300;
                    else if(emptyNum == 2)          //活二
                        score+=700;
                }
                else if (friendPieceNum == 2){
                    if (emptyNum == 1)                // 死三
                        score += 1000;
                    else if (emptyNum == 2)
                        score += 3000;               // 活三
                }
                else if (friendPieceNum == 3){
                    if (emptyNum == 1)                // 死四
                        score += 10000;
                    else if (emptyNum == 2)
                        score += 20000;              // 活四
                }
                else if (friendPieceNum >= 4)
                    score += 200000;                // 活五
            }
        }
    }

    //另外，根据棋子在棋盘上的位置给棋子加分，这部分加分不会影响棋型关系，但会使程序更偏向于在棋盘中央处下棋
    score+=10-abs(x-colNum/2);
    score+=10-abs(y-rowNum/2);

    return score;
}

void Game::restart(){
    memset(board, 0, sizeof(board));
    repaint();
    gameStatus=PLAYING;
    pieceNum=0;
    move.clear();
}

void Game::hint(){
    AIAct();
    repaint();
    if(gameFlag == PVE && gameStatus == PLAYING)
        AIAct();
}

void Game::retract(){
    if(!move.empty() && gameStatus != END){
        Point cur=move.last();
        move.pop_back();
        board[cur.x][cur.y]=EMPTY;
        switchColor();
        if(gameFlag == PVE){
            //PVE悔棋要一次悔两步，否则可能出现玩家和电脑交换颜色的情况
            cur=move.last();
            move.pop_back();
            board[cur.x][cur.y]=EMPTY;
            switchColor();
        }
        repaint();
        gameStatus=PLAYING;
    }
}

void Game::remindLastMove(){
    const int blockSize=10;
    if(!move.empty()){
    Point cur=move.last();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen;
    if(curColor == WHITE){
        pen.setColor(Qt::white);
    }else{
        pen.setColor(Qt::black);
    }
    painter.setPen(pen);
    painter.drawLine(originX+cur.x*xInterval-blockSize/2, originY+cur.y*yInterval-blockSize/2,
                     originX+cur.x*xInterval-blockSize/2, originY+cur.y*yInterval+blockSize/2);
    painter.drawLine(originX+cur.x*xInterval-blockSize/2, originY+cur.y*yInterval+blockSize/2,
                     originX+cur.x*xInterval+blockSize/2, originY+cur.y*yInterval+blockSize/2);
    painter.drawLine(originX+cur.x*xInterval+blockSize/2, originY+cur.y*yInterval+blockSize/2,
                     originX+cur.x*xInterval+blockSize/2, originY+cur.y*yInterval-blockSize/2);
    painter.drawLine(originX+cur.x*xInterval+blockSize/2, originY+cur.y*yInterval-blockSize/2,
                     originX+cur.x*xInterval-blockSize/2, originY+cur.y*yInterval-blockSize/2);
    }
}

void Game::createReplayFile(){
    //创建复盘文件
    QString timeString, pathString="data/replay/";
    QDateTime time;
    time=QDateTime::currentDateTime();
    timeString=time.toString("yyyy-MM-dd-hh-mm-ss");
    pathString.append(timeString);
    pathString.append('_');
    pathString.append(p->getUsername());
    QFile file(pathString);
    file.open(QIODevice::WriteOnly);
    QDataStream fstream(&file);
    while (!move.empty()) {
        Point cur=move.first();
        move.pop_front();
        fstream << (qint32)cur.x << (qint32)cur.y;
    }
}

void Game::AIMoveFirst(){
    AIAct();
}
