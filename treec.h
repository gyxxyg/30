#ifndef TREEC_H
#define TREEC_H

#include <QDialog>
#include<QTimer>
namespace Ui {
class treec;
}

class treec : public QDialog
{
    Q_OBJECT

public:
    QTimer *timer ;
    int x,y,has,haschild;
    int Hp;
    int hasat;

public:
    explicit treec(QWidget *parent = 0);
    ~treec();
    void move();

private:
    Ui::treec *ui;
protected:
};

#endif // TREEC_H
