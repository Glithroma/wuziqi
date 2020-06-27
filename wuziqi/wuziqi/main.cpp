#include "mainwindow.h"
#include "registeraccount.h"
#include <iostream>
#include <QApplication>
#include <QtDebug>
#include <QDir>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.a=&a;
    w.setWindowTitle("五子棋");
    w.show();

    return a.exec();
}
