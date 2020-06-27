#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
class MainWindow;

namespace Ui {
class changePassword;
}

class changePassword : public QWidget
{
    Q_OBJECT

public:
    explicit changePassword(MainWindow* p, QWidget *parent = nullptr);
    ~changePassword();
    void showInterface();

private:
    Ui::changePassword *ui;
    MainWindow *p;
    void closeEvent(QCloseEvent *event);

private slots:
    void confirm();
    void back();
};

#endif // CHANGEPASSWORD_H
