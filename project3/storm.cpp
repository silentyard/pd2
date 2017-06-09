#include "storm.h"
#include"battleunit.h"
#include<QGraphicsItem>
#include"graphicsview.h"

#include<QList>
#include<qmath.h>

#include<QDebug>

extern graphicsView *w;
Storm::Storm(): dps(10),count(0)
{
    bullet = new QGraphicsPixmapItem;
    bullet->setPixmap(QPixmap(":/image/basebullet.png").scaled(50,50));
    bullet->setPos(w->bluedeck->pos[0]);

    mv_timer = new QTimer;
    connect(mv_timer,SIGNAL(timeout()),this,SLOT(move()));
    mv_timer->start(100);


    range = new QGraphicsEllipseItem(0,0,150,150,this);
    range->hide();
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(hit()));
}

void Storm::move(){
    trace = new QLineF(w->bluedeck->pos[0],
            QPointF(this->pos())+QPointF(25,25));
    double step = trace->length()/15;
    double dx = step * qCos(-1*qDegreesToRadians(trace->angle()));
    double dy = step *qSin(-1*qDegreesToRadians(trace->angle()));
    bullet->setPos(bullet->x()+dx,bullet->y()+dy);
    count+=1;
    if(count>15){
        mv_timer->stop();
        scene()->removeItem(bullet);
        setPixmap(QPixmap(":/image/storm.png").scaled(150,150));
        timer->start(1000);
    }
}

void Storm::hit(){
    QList<QGraphicsItem*> items = range->collidingItems();
    for(int i=0;i<items.size();i++){
        BattleUnit *enemy = dynamic_cast<BattleUnit*>(items[i]);
        if(enemy){
            if(enemy->getcamp()==0)
                enemy->bleed(dps);
        }
    }
    count+=1;
    if(count>25)
        delete this;
}

void Storm::shoot(){
    scene()->addItem(bullet);
}
