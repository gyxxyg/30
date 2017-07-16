#include "bzwd.h"
#include "ui_bzwd.h"

bzwd::bzwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bzwd)
{
    ui->setupUi(this);
}

bzwd::~bzwd()
{
    delete ui;
}
