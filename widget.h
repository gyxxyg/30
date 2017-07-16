#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QList>
#include"treec.h"
#include"drop.h"
#include"de.h"
#include"push.h"
#include"book.h"
#include"huaji.h"
#include"hb.h"
#include"hat.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    int count;
    QTimer *timer;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QList<treec*> trees;
    QList<drop*> drops;
    QList<de*> des;
    QList<push*> pushs;
    QList<book*> books;
    QList<hb*> hbs;
    QList<hat*> hats;
    int dragx,dragy;
    int hjs;
    int hastrees[5][9];
    int hasz[1000][9];
    int judge();
    int hashb(int wit);
    int judgedie();

private:
    Ui::Widget *ui;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();
    void tocontinue();
    void restart();
};

#endif // WIDGET_H
