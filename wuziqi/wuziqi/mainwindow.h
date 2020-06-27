#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registeraccount.h"
#include "mainmenu.h"
#include "changepassword.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QApplication *a;
private:
    registerAccount registerAccountInterface;
    mainMenu menu;
    changePassword change;
private slots:
    void login();
    void registerAccount();
    void changePassword();
};
#endif // MAINWINDOW_H
