#include "cd.h"
#include "ui_cd.h"
#include"bzwd.h"
cd::cd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

cd::~cd()
{
    delete ui;
}

void cd::on_pushButton_clicked()
{
    emit tocontinue();
    close();
}

void cd::on_pushButton_2_clicked()
{
    emit torestart();
    close();
}

void cd::on_pushButton_3_clicked()
{
    bzwd *bzwdc = new bzwd;
    bzwdc->show();
}

void cd::on_pushButton_4_clicked()
{
    emit toclose();
    close();
}
