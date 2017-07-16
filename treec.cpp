#include "treec.h"
#include "ui_treec.h"
#include<QPixmap>
#include<QPainter>
#include<QDebug>
#include<QTimer>
treec::treec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::treec)
{
    ui->setupUi(this);
    x=0,y=0,has=0,haschild = 0;
    Hp = 3;
    hasat = 0;
}

treec::~treec()
{
    delete ui;
}

