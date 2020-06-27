#ifndef GUIDE_H
#define GUIDE_H

#include <QWidget>

class mainMenu;

namespace Ui {
class guide;
}

class guide : public QWidget
{
    Q_OBJECT

public:
    explicit guide(mainMenu *p, QWidget *parent = nullptr);
    ~guide();

private:
    Ui::guide *ui;
    mainMenu *p;

private slots:
    void backtoMM();
};

#endif // GUIDE_H
