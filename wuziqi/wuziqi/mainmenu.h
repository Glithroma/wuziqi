#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "guide.h"
#include "game.h"
#include "replay.h"
class MainWindow;

namespace Ui {
class mainMenu;
}

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainMenu(MainWindow *p, QWidget *parent = nullptr);
    ~mainMenu();
    void setUsername(QString &name);
    QString& getUsername();
    MainWindow *p;

private:
    Ui::mainMenu *ui;
    void closeEvent(QCloseEvent *event);
    guide *gui;
    Game *game;
    Replay *repl;
    QString username;

private slots:
    void PVPGame();
    void PVEGame();
    void replay();
    void guide();
    void exitGame();
    void changeAccount();
};

#endif // MAINMENU_H
