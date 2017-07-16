#include "hb.h"
#include<QTime>
#include<QTimer>
#include<QDebug>
hb::hb()
{
    x = 1000;
   // qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand = qrand()%5;
    qDebug()<<rand;
    y = 100+rand*126;
    v = 40;
    Hp = 400;
    cdt =0;
    v1 = 40;
    atd = 0;
    hashat = -1;
}
