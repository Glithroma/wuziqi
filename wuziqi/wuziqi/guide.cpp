#include "guide.h"
#include "ui_guide.h"

guide::guide(mainMenu *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guide)
{
    this->p=p;
    ui->setupUi(this);
    this->setWindowTitle("游戏说明");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backtoMM()));
}

guide::~guide()
{
    delete ui;
}

void guide::backtoMM(){
    this->close();
}
