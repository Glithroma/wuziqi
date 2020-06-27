#ifndef GAME_H
#define GAME_H

#include <QWidget>

class mainMenu;

const int EMPTY=0, BLACK=1, WHITE=2;
const int PVP=1, PVE=2;
const int END=0, PLAYING=1;
const int INF=0x3f3f3f;

namespace Ui {
class Game;
}

struct Point{
    qint32 x, y;
    Point(int a, int b): x(a), y(b){}
    Point(){}
};

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(int gameMode, mainMenu *p, QWidget *parent = nullptr);
    ~Game();
    void AIMoveFirst();

private:
    Ui::Game *ui;
    mainMenu *p;

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void switchColor();
    int oppositeColor(int color);
    bool checkWin(int x, int y);
    bool checkDraw();
    void AIAct();
    void remindLastMove();
    int evaluate(int x, int y, int color);
    void createReplayFile();
    void getNeighbor(QVector<Point> &v);
    int findBestPoint(QVector<Point> neighborPoint, int beta, int color, int count);

    int curCol, curRow;
    int board[15][15];
    int curColor;
    int gameFlag;
    int pieceNum;
    int gameStatus;
    bool hardMode;
    QVector<Point> move;
private slots:
    void retract();
    void hint();
    void restart();
    void exit();
};


#endif // GAME_H
