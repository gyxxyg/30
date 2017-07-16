#include "widget.h"
#include "ui_widget.h"
#include"treec.h"
#include<QPainter>
#include<QDebug>
#include<QDrag>
#include"drop.h"
#include"de.h"
#include"book.h"
#include"hb.h"
#include"hat.h"
#include<QString>
#include<QFrame>
#include<QPushButton>
#include"cd.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    count = 0;
    hjs = 500;
    memset(hastrees,0,sizeof(hastrees));
    memset(hasz,0,sizeof(hasz));
}

Widget::~Widget()
{
    delete ui;
}
int Widget::judgedie()
{
    for(int i = 0;i<hbs.size();i++)
    {
        if(hbs[i]->x<0)
            return 1;
    }
    return 0;
}

int Widget::judge()
{
    for(int i = 0 ; i< books.size();i++)
        for(int j = 0 ; j<hbs.size();j++)
        {
            if(books[i]->x+53>=hbs[j]->x&&books[i]->x<hbs[j]->x+70)
                if((books[i]->y-100)/126==(hbs[j]->y-100)/126)
                {
                    books[i]->hasat = 1;
                    hbs[j]->Hp -= 100;
                    if(hbs[j]->Hp<=0)
                        hbs[j]->atd = 1;
                }
        }
    return 0;
}
int Widget::hashb(int wit)
{
    for(int i = 0;i<hbs.size();i++)
    {
        if(wit == (hbs[i]->y-100)/126)
            return 1;
    }
    return 0;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPixmap pix(size());
    QPainter painter(&pix);
    if(judgedie()==1)
    {

        painter.drawPixmap(0,0,1000,712,QPixmap(":/new/prefix1/map.png"));
        painter.drawPixmap(37,18,50,50,QPixmap(":/new/prefix1/huaji.png"));
        painter.drawText(40,95,QString::number(hjs));
        painter.drawPixmap(110,0,100,100,QPixmap(":/new/prefix1/tree.png"));
        painter.drawPixmap(230,0,100,100,QPixmap(":/new/prefix1/drop1.png"));
        painter.drawPixmap(350,0,100,100,QPixmap(":/new/prefix1/de1.png"));
        painter.drawPixmap(470,0,100,100,QPixmap(":/new/prefix1/1.png"));
        painter.setBrush(QColor(0,0,0,200));
        painter.drawRect(0,0,1000,712);
        painter.drawPixmap(250,100,500,500,QPixmap(":/new/prefix1/js.png"));

    }
    else
    {
        count += 1;
    if(count>=100)
    {
        int level = (count-100)/3000;
        if((count-100)%3000<=10&&(count-((count-100)/3000*3000))%20==0)
        {
            hb *hbc = new hb;
            hbc->Hp += level*100;
            hbs<<hbc;
        }
        else
        {
            if((count-((count-100)/3000*3000))%50==0)
            {
                hb *hbc = new hb;
                hbc->Hp += level*100;
                hbs<<hbc;

            }
        }
    }
    painter.drawPixmap(0,0,1000,712,QPixmap(":/new/prefix1/map.png"));
    painter.drawPixmap(37,18,50,50,QPixmap(":/new/prefix1/huaji.png"));
    painter.drawText(40,95,QString::number(hjs));
    painter.drawPixmap(110,0,100,100,QPixmap(":/new/prefix1/tree.png"));
    painter.drawPixmap(230,0,100,100,QPixmap(":/new/prefix1/drop1.png"));
    painter.drawPixmap(350,0,100,100,QPixmap(":/new/prefix1/de1.png"));
    painter.drawPixmap(470,0,100,100,QPixmap(":/new/prefix1/1.png"));
    for(int i = 0; i <trees.size();i++)
    {
        painter.drawPixmap(trees[i]->x,trees[i]->y,100,126,QPixmap(":/new/prefix1/tree.png"));
        if(trees[i]->haschild == 1)
        {
            painter.drawPixmap(trees[i]->x+50,trees[i]->y+76,50,50,QPixmap(":/new/prefix1/huaji.png"));
        }
        trees[i]->has += 1;
        if(trees[i]->has == 80)
        {
            trees[i]->haschild = 1;
            trees[i]->has = 0;
        }
        if(trees[i]->has == 40)
            if(trees[i]->haschild == 1)
                trees[i]->haschild = 0;
    }
    for(int i = 0 ;i<drops.size();i++)
    {
        if(drops[i]->has<20||hashb((drops[i]->y-100)/126)==0)
        {
            painter.drawPixmap(drops[i]->x,drops[i]->y+40,80,86,QPixmap(":/new/prefix1/drop1.png"));
            painter.drawPixmap(drops[i]->x+20,drops[i]->y,53,40,QPixmap(":/new/prefix1/book.png"));

        }
        else if(drops[i]->has>=20&&hashb((drops[i]->y-100)/126)==1)
        {
            painter.drawPixmap(drops[i]->x,drops[i]->y+40,80,86,QPixmap(":/new/prefix1/drop2.png"));
            if(drops[i]->has == 20)
            {
                book *bookc = new book;
                bookc->x = drops[i]->x+100;
                bookc->y = drops[i]->y;
                books<<bookc;
            }

        }
        drops[i]->has += 1;
        if(drops[i]->has == 40)
            drops[i]->has = 0;
    }
    for(int i = 0 ;i<des.size();i++)
    {
        if(des[i]->upon<10)
            painter.drawPixmap(des[i]->x,des[i]->y,100,126,QPixmap(":/new/prefix1/de1.png"));
        else if(des[i]->upon >=10)
            painter.drawPixmap(des[i]->x,des[i]->y,100,126,QPixmap(":/new/prefix1/de2.png"));
        des[i]->upon += 1;
        if(des[i]->upon ==20)
            des[i]->upon = 0;
    }
    for(int i = 0 ;i<pushs.size();i++)
    {
        if(pushs[i]->has<20||hashb((pushs[i]->y-100)/126)==0)
        {
            painter.drawPixmap(pushs[i]->x,pushs[i]->y+40,80,86,QPixmap(":/new/prefix1/1.png"));
            painter.drawPixmap(pushs[i]->x,pushs[i]->y,68,40,QPixmap(":/new/prefix1/hat.png"));
        }
        else if(pushs[i]->has >= 20&&hashb((pushs[i]->y-100)/126)==1)
        {
            int length = 1000;
            int hbstart ;
            int hbv;

            if(pushs[i]->has==20)
            {
                hat *hatc = new hat;
                hatc->x = pushs[i]->x;
                hatc->y = pushs[i]->y;
                hatc->y0 = pushs[i]->y;
                int jx;

                for(int j=0;j<hbs.size();j++)
                {
                  if((hbs[j]->y-100)/126==(hatc->y-100)/126)
                   {
                        int temp = hbs[j]->x+35 - hatc->x-34;
                        if(length>temp)
                        {
                            length = temp;
                            hbstart = hbs[j]->cdt;
                            jx = j;
                        }
                   }
                 }
                if(length<=500&&length>=100)
                {
                    if(hastrees[(hbs[jx]->x-50)/100][(hbs[jx]->y-100)/126]==1)
                        hbv = 0;
                    else if(hbstart == 19)
                        hbv = 80/2;
                    else
                        hbv = 20;
                    hatc->vx = (length/2-hbv)/10;
                    hatc->ay = length/10;
                    hatc->vy = length/10;
                    hats<<hatc;
                }
                else if(length<100)
                {

                    if(hbstart == 19)
                        hbv = 80/2;
                    else
                        hbv = 20;
                    hatc->vx = (length-hbv)/10.0;
                    hatc->ay = length/10.0;
                    hatc->vy = length/10.0;
                    hats<<hatc;
                }
                else
                {
                    delete hatc;

                }
             }
            if(length>500)
            {
                painter.drawPixmap(pushs[i]->x,pushs[i]->y+40,80,86,QPixmap(":/new/prefix1/1.png"));
                painter.drawPixmap(pushs[i]->x,pushs[i]->y,68,40,QPixmap(":/new/prefix1/hat.png"));
            }
            else
                painter.drawPixmap(pushs[i]->x,pushs[i]->y+40,80,86,QPixmap(":/new/prefix1/2.png"));
        }
        pushs[i]->has += 1;
        if(pushs[i]->has == 40)
            pushs[i]->has = 0;
    }
    for(int i = 0;i<books.size();i++)
    {
        if(books[i]->toward<6)
        {
            painter.drawPixmap(books[i]->x,books[i]->y,53,40,QPixmap(":/new/prefix1/book.png"));
            books[i]->toward += 1;
        }
        else if(books[i]->toward<11)
        {
            painter.drawPixmap(books[i]->x,books[i]->y,40,53,QPixmap(":/new/prefix1/book2.png"));
            books[i]->toward += 1;
        }
        else if(books[i]->toward<16)
        {
            painter.drawPixmap(books[i]->x,books[i]->y,53,40,QPixmap(":/new/prefix1/book3.png"));
            books[i]->toward += 1;
        }
        else if(books[i]->toward<=20)
        {
            painter.drawPixmap(books[i]->x,books[i]->y,40,53,QPixmap(":/new/prefix1/book4.png"));
            books[i]->toward += 1;
            if(books[i]->toward==21)
                books[i]->toward=1;
        }
        books[i]->x+=books[i]->v;
        if(books[i]->x>1000)
            books.removeAt(i);
    }
    for(int i=0;i<hats.size();i++)
    {
        painter.drawPixmap(hats[i]->x,hats[i]->y,68,40,QPixmap(":/new/prefix1/hat.png"));
        hats[i]->x += hats[i]->vx;
        hats[i]->y -= hats[i]->vy;
        hats[i]->vy -= hats[i]->ay/10;
        for(int j=0;j<hbs.size();j++)
        {
            if((hats[i]->y0-100)/126==(hbs[j]->y-100)/126)
                if(hats[i]->x+68>=hbs[j]->x&&hats[i]->x<hbs[j]->x+70)
                {
                    hats[i]->hasat = 1;
                    hbs[j]->Hp -= 50;
                    hbs[j]->hashat = 5;
                    if(hbs[j]->Hp<=0)
                        hbs[j]->atd = 1;
                }
        }
        if(hats[i]->y>hats[i]->y0)
            hats[i]->hasat = 1;
    }
    for(int i=0;i<hats.size();i++)
    {
        if(hats[i]->hasat ==1)
        {
            hastrees[(hats[i]->x-50)/100][(hats[i]->y-100)/126] = 0;
            hats.removeAt(i);
            i = 0;
        }
    }
    judge();
    for(int i =0 ; i<books.size();i++)
    {
        if(books[i]->hasat == 1)
        {
            hastrees[(books[i]->x-50)/100][(books[i]->y-100)/126] = 0;
            books.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<des.size();i++)
    {
        if(des[i]->hasat == 1)
        {
            hastrees[(des[i]->x-50)/100][(des[i]->y-100)/126] = 0;
            des.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<trees.size();i++)
    {
        if(trees[i]->hasat == 1)
        {
            hastrees[(trees[i]->x-50)/100][(trees[i]->y-100)/126] = 0;
            trees.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<pushs.size();i++)
    {
        if(pushs[i]->hasat == 1)
        {
            hastrees[(pushs[i]->x-50)/100][(pushs[i]->y-100)/126] = 0;
            pushs.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<drops.size();i++)
    {
        if(drops[i]->hasat == 1)
        {
            hastrees[(drops[i]->x-50)/100][(drops[i]->y-100)/126] = 0;
            drops.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<hbs.size();i++)
    {
        if(hbs[i]->atd == 1)
        {
            hbs.removeAt(i);
            i = 0;
        }
    }
    for(int i = 0;i<hbs.size();i++)
    {
        if(hbs[i]->cdt<20&&hastrees[(hbs[i]->x-50)/100][(hbs[i]->y-100)/126]==0)
        {
            painter.drawPixmap(hbs[i]->x,hbs[i]->y+40,70,86,QPixmap(":/new/prefix1/hb2.png"));
            if(hbs[i]->cdt==19)
                hbs[i]->x -=hbs[i]->v;
        }
        else if(hbs[i]->cdt>=20||hastrees[(hbs[i]->x-50)/100][(hbs[i]->y-100)/126]==1)
        {
            painter.drawPixmap(hbs[i]->x,hbs[i]->y+40,70,86,QPixmap(":/new/prefix1/hb1.png"));

        }
        hbs[i]->cdt += 1;
        if(hbs[i]->cdt == 39)
        {
            if(hastrees[(hbs[i]->x-50)/100][(hbs[i]->y-100)/126]==0)
            {
                hbs[i]->cdt = 0;
                hbs[i]->x -=hbs[i]->v1;
            }
            else
            {
                hbs[i]->cdt -= 1;
                for(int j =0;j<des.size();j++)
                {
                    if((des[j]->x-50)/100==(hbs[i]->x-50)/100)
                        if((hbs[i]->y-100)/126==(des[j]->y-100)/126)
                        {
                            des[j]->Hp -= 1;
                            if(des[j]->Hp<=0)
                                des[j]->hasat = 1;
                        }
                }
                for(int j =0;j<drops.size();j++)
                {
                    if((drops[j]->x-50)/100==(hbs[i]->x-50)/100)
                        if((hbs[i]->y-100)/126==(drops[j]->y-100)/126)
                        {
                            drops[j]->Hp -= 1;
                            if(drops[j]->Hp<=0)
                                drops[j]->hasat = 1;
                        }
                }
                for(int j =0;j<pushs.size();j++)
                {
                    if((pushs[j]->x-50)/100==(hbs[i]->x-50)/100)
                        if((hbs[i]->y-100)/126==(pushs[j]->y-100)/126)
                        {
                            pushs[j]->Hp -= 1;
                            if(pushs[j]->Hp<=0)
                                pushs[j]->hasat = 1;
                        }
                }
                for(int j =0;j<trees.size();j++)
                {
                    if((trees[j]->x-50)/100==(hbs[i]->x-50)/100)
                        if((hbs[i]->y-100)/126==(trees[j]->y-100)/126)
                        {
                            trees[j]->Hp -= 1;
                            qDebug()<<trees[j]->Hp<<"hlhzz";
                            if(trees[j]->Hp<=0)
                                trees[j]->hasat =1;
                        }
                }
            }
        }
        if(hbs[i]->hashat > 0 )
        {
            painter.drawPixmap(hbs[i]->x,hbs[i]->y,86,40,QPixmap(":/new/prefix1/hat.png"));
            hbs[i]->Hp -= 50;
            if(hbs[i]->Hp<=0)
                hbs[i]->atd = 1;
            hbs[i]->hashat -= 1;
        }
    }
    }
    QPainter painter2(this);
    painter2.drawPixmap(0,0,1000,712,pix);
    //qDebug()<<"shjbcksdjbc";
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)
    {
        event->ignore();
        return;
    }
    dragx = event->pos().x();
    dragy = event->pos().y();
    for(int i = 0; i<trees.size();i++)
    {
        if(dragx>=trees[i]->x+50&&dragx<trees[i]->x+100)
            if(dragy>=trees[i]->y+76&&dragy<trees[i]->y+126)
                if(trees[i]->haschild == 1)
                {
                    trees[i]->haschild = 0;
                    hjs += 25;
                }
    }
    setCursor(Qt::ClosedHandCursor);
}
void  Widget::mouseMoveEvent(QMouseEvent *event)
{
    QDrag *drag = new QDrag(this);
    QPixmap pix(":/new/prefix1/tree.png");
    drag->setMimeData(0);
    drag->setPixmap(pix);
    drag->setHotSpot(QPoint(50,50));
    drag->exec();
    setCursor(Qt::OpenHandCursor);
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    int pup = count/600*10;
    if(dragx>=110&&dragx<230&&dragy<100&&hjs>=(50)&&hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126]==0)
    {
        treec *tree = new treec;
        tree->x = (event->pos().x()-50)/100*100+50;
        tree->y = (event->pos().y()-100)/126*126+100;
        hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126] = 1;
        if(event->pos().y()>100)
            trees<<tree;
        hjs -= 50;
    }
    else if(hjs>=(150)&&dragx>=230&&dragx<350&&dragy<100&&hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126]==0)
    {
        drop *dropc = new drop;
        dropc->x =(event->pos().x()-50)/100*100+50;
        dropc->y =(event->pos().y()-100)/126*126+100;
        hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126] = 1;
        if(event->pos().y()>100)
            drops<<dropc;
        hjs -= 150;
    }
    else if(hjs>=(75)&&dragx>=350&&dragx<470&&dragy<100&&hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126]==0)
    {
        de *dec = new de;
        dec->x =(event->pos().x()-50)/100*100+50;
        dec->y =(event->pos().y()-100)/126*126+100;
        hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126] = 1;
        if(event->pos().y()>100)
            des<<dec;
        hjs -= 75;
    }
    else if(hjs>=(200)&&dragx>=470&&dragx<590&&dragy<100&&hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126]==0)
    {
        push *pushc = new push;
        pushc->x =(event->pos().x()-50)/100*100+50;
        pushc->y =(event->pos().y()-100)/126*126+100;
        hastrees[(event->pos().x()-50)/100][(event->pos().y()-100)/126] = 1;
        if(event->pos().y()>100)
            pushs<<pushc;
        hjs -= 200;
    }
    setCursor(Qt::OpenHandCursor);
}
void Widget::tocontinue()
{
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
}
void Widget::restart()
{
    close();
    Widget *w = new Widget;
    w->show();
}

void Widget::on_pushButton_clicked()
{
    timer->stop();
    cd *cdc = new cd(this);
    connect(cdc,SIGNAL(tocontinue()),this,SLOT(tocontinue()));
    connect(cdc,SIGNAL(toclose()),this,SLOT(close()));
    connect(cdc,SIGNAL(torestart()),this,SLOT(restart()));
    cdc->show();
}
