#include "base.h"
#include"basebullet.h"
#include"battleunit.h"

#include<QPen>
#include<QPointF>
#include<QVector>
#include<QList>
#include<QPolygonF>
#include<QTimer>
#include<QLineF>
#include<QBrush>
#include<QPen>
#include<QDebug>

#include<graphicsview.h>
#include<bluemeleeicon.h>

extern graphicsView *w;
Base::Base(bool value,QObject *parent) :
    BattleUnit(value,0,atk=50,max_hp=1000,speed=0,70,size=100)
{
    disconnect(atk_timer);
    connect(atk_timer,SIGNAL(timeout()),this,SLOT(detect()));
}

void Base::bleed(int dmg)
{
    hp-=dmg;
    scene()->removeItem(current_hp);
    current_hp = new QGraphicsRectItem(0,0,100.0*(hp/1000.0),5,this);
    current_hp->setBrush(QBrush(Qt::red));

    if(hp<=0){
        if(this->objectName()=="purplebase"){
            QGraphicsTextItem *text = new QGraphicsTextItem;
            text->setPlainText(QString("You win"));
            text->setPos(400,400);
            text->setFont(QFont("time",40));
            w->game_timer->stop();
            w->rktime<<w->gametime;
            w->showranking();
            w->summary->addItem(text);
            w->setScene(w->summary);
        }
        else if(this->objectName()=="bluebase"){
            QGraphicsTextItem *text = new QGraphicsTextItem;
            text->setPlainText(QString("You lose"));
            text->setPos(400,400);
            text->setFont(QFont("time",40));
            w->game_timer->stop();
            w->summary->addItem(text);
            w->setScene(w->summary);
        }

        delete this;
    }
}

void Base::detect(){
    QList<QGraphicsItem*> collidings = atk_range->collidingItems();
    if(collidings.size()==1)
        return;
    for(int i=collidings.size()-1;i>=0;i--){
        if(typeid(*collidings[i])==typeid(BattleUnit)){
            BattleUnit *enemy = dynamic_cast<BattleUnit*>(collidings[i]);
            if(enemy->getcamp()!=this->camp){
                atk_dest = enemy->pos();
                attack();
                enemy->bleed(atk);
                return;
            }
        }
    }
}

void Base::attack(){
    basebullet *ball = new basebullet;
    ball->setPos(x()+50,y()+50);
    QLineF ln(QPointF(ball->pos()),atk_dest);
    ball->setRotation(-1 * ln.angle());
    scene()->addItem(ball);
}
