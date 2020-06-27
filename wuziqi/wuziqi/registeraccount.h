#ifndef REGISTERACCOUNT_H
#define REGISTERACCOUNT_H

#include <QWidget>

class MainWindow;

namespace Ui {
class registerAccount;
}

class registerAccount : public QWidget
{
    Q_OBJECT

public:
    explicit registerAccount(MainWindow* p, QWidget *parent = nullptr);
    ~registerAccount();
    void showInterface();

private:
    Ui::registerAccount *ui;
    MainWindow *p;
    void closeEvent(QCloseEvent *event);
private slots:
    void closeRegisterInterface();
    void registerPlayer();
};

#endif // REGISTERACCOUNT_H
