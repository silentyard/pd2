#include "heroicon.h"
#include"hero.h"
#include"graphicsview.h"

#include<QGraphicsScene>
#include<QRectF>
#include<QBrush>

extern graphicsView *w;
HeroIcon::HeroIcon():power(0)
{
    setPixmap(QPixmap(":/image/baronicon.jpeg").scaled(100,100));
    max_power = new QGraphicsRectItem(QRectF(0,105,100,5),this);
    current_power = new QGraphicsRectItem(QRectF(0,105,0,5),this);
    current_power->setBrush(QBrush(Qt::blue));
}

void HeroIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(power>=10){
        power=-1;
        charge();
        w->baron = new Hero;
        w->baron->setPos(350,500);
        scene()->addItem(w->baron);
    }
}

void HeroIcon::charge()
{
    if(!(w->baron)){
    (power<10) ? (power+=1) : (power=10);
    scene()->removeItem(current_power);
    current_power = new QGraphicsRectItem(QRectF(0,105,power*10,5),this);
    current_power->setBrush(QBrush(Qt::blue));
    }
}
