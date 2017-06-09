#include "hero.h"
#include"battleunit.h"
#include"graphicsview.h"

#include<QRectF>
#include<QGraphicsScene>
#include<QList>
#include<QDebug>

extern graphicsView *w;
Hero::Hero():count(30),bullet(nullptr)
{
    setPixmap(QPixmap(":/image/baron.png").scaled(100,100));

    max_power = new QGraphicsRectItem(QRectF(0,105,100,5),this);
    current_power = new QGraphicsRectItem(QRectF(0,105,100,5),this);
    current_power->setBrush(QBrush(Qt::green));

    timer = new QTimer;
    b_timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(downcount()));
    connect(b_timer,SIGNAL(timeout()),this,SLOT(bulletfly()));

    timer->start(1000);
}

void Hero::downcount()
{
     count-=1;
     scene()->removeItem(current_power);
     current_power = new QGraphicsRectItem(QRectF(0,105,
                                                  double(100.0/30.0*count),5),this);
     current_power->setBrush(QBrush(Qt::green));

     if(count<=0)
         delete this;
}

void Hero::attack()
{
    if(!bullet){
        bullet = new QGraphicsPixmapItem;
        bullet->setPixmap(QPixmap(":/image/tennis.png").scaled(50,50));
        bullet->setPos(this->pos()+QPointF(25,-10));
        scene()->addItem(bullet);
        b_timer->start(100);
    }
}

void Hero::bulletfly()
{
    bullet->setPos(bullet->x(),bullet->y()-20);
    QList<QGraphicsItem*>items = bullet->collidingItems();

    for(int i=0;i<items.size();++i){
        BattleUnit *enemy  = dynamic_cast<BattleUnit*>(items[i]);
        if(enemy && enemy->getcamp()==0){
            enemy->bleed(20);
            scene()->removeItem(bullet);
            bullet=nullptr;
            b_timer->stop();
            return;
        }
    }
    if(bullet->y()<=0){
        b_timer->stop();
        scene()->removeItem(bullet);
        bullet=nullptr;
    }
}

Hero::~Hero()
{
    delete bullet;
    w->baron = nullptr;
}
