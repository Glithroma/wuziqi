#ifndef REPLAY_H
#define REPLAY_H

#include <QWidget>
#include <QFile>

class mainMenu;

namespace Ui {
class replay;
}

struct qint32Point{
    qint32 x, y;
    qint32Point(qint32 a, qint32 b): x(a), y(b){}
    qint32Point(const qint32Point &e){
        x=e.x;
        y=e.y;
    }
    qint32Point(){}
};

class Replay : public QWidget
{
    Q_OBJECT

public:
    explicit Replay(QString fName, mainMenu *p, QWidget *parent = nullptr);
    ~Replay();

private:
    Ui::replay *ui;

    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
    void switchColor();

    QString fileName;
    mainMenu *p;
    int board[15][15];
    QVector<qint32Point> fileMove, curMove;
    QFile file;
    int curColor;
private slots:
    void exit();
    void nextMove();
    void prevMove();
    void rename();
};

#endif // REPLAY_H
