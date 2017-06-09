#include "battleunit.h"
#include<qmath.h>
#include<QDebug>
#include<QBrush>
#include<QPen>
#include<QGraphicsScene>
#include"graphicsview.h"

extern graphicsView *w;
BattleUnit::BattleUnit(bool camp, int initx, int atk, double max_hp, int speed,int range
                       ,int size, QGraphicsItem *parent):camp(camp),atk(atk)
                        ,max_hp(max_hp),hp(max_hp),speed(speed),atk_dist(range),size(size),has_target(0),point_index(0)
{
    if(camp==1){
        if(initx<=400)
            move_path<<QPointF(200,200)<<QPointF(400,100);
        else
            move_path<<QPointF(600,200)<<QPointF(400,100);
    }
    else{
        if(initx<=400)
            move_path<<QPointF(200,600)<<QPointF(400,700);
        else
            move_path<<QPointF(600,600)<<QPointF(400,700);
    }

    mv_timer = new QTimer;
    atk_timer = new QTimer;
    connect(mv_timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(atk_timer,SIGNAL(timeout()),this,SLOT(detect()));
    mv_timer->start(150);
    atk_timer->start(1000);

    atk_range_points << QPointF(-0.5,-1.5) << QPointF(0.5,-1.5)<<QPointF(1.5,-0.5)
           <<QPointF(1.5,0.5)<<QPointF(0.5,1.5)<<QPointF(-0.5,1.5)
          <<QPointF(-1.5,0.5)<<QPointF(-1.5,-0.5);

    for(int i =0;i<atk_range_points.size();i++){
        atk_range_points[i]*=range;
        atk_range_points[i]+=QPointF(size/2,size/2);
    }

    atk_range = new QGraphicsPolygonItem(QPolygonF(atk_range_points),this);
    atk_range->setPen(QPen(Qt::DotLine));

    maxhp = new QGraphicsRectItem(0,0,size,5,this);
    current_hp = new QGraphicsRectItem(0,0,size,5,this);
    current_hp->setBrush(QBrush(Qt::red));
}

void BattleUnit::bleed(int dmg)
{
    hp-=dmg;

    scene()->removeItem(current_hp);
    current_hp = new QGraphicsRectItem(0,0,double(size)*(hp/max_hp),5,this);
    current_hp->setBrush(QBrush(Qt::red));

    if(hp<=0){
        if(this->objectName()=="purplebase"){
            QGraphicsTextItem *text = new QGraphicsTextItem;
            text->setPlainText(QString("You win"));
            text->setPos(350,400);
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
            text->setPos(350,400);
            text->setFont(QFont("time",40));
            w->game_timer->stop();
            w->summary->addItem(text);
            w->setScene(w->summary);
        }
        w->icon->charge();
        delete this;
    }
}

bool BattleUnit::getcamp()
{
    return camp;
}

void BattleUnit::move()
{
    if(has_target==0){
        QLineF ln(pos(),move_path[point_index]);
        if(ln.length()<5 && point_index < move_path.size()-1){
            point_index++;
            ln = QLineF(pos(),move_path[point_index]);
        }
        double dx = speed * qCos(-1*qDegreesToRadians(ln.angle()));
        double dy= speed * qSin(-1*qDegreesToRadians(ln.angle()));
        setPos(x()+dx,y()+dy);
    }
}

void BattleUnit::detect()
{
    QList<QGraphicsItem*>collidings = atk_range->collidingItems();
    if(collidings.size()<=1){
        has_target=0;
        return;
    }

    for(int i = collidings.size()-1;i>=0;i--){
        BattleUnit *enemy = dynamic_cast<BattleUnit*>(collidings[i]);
        if(enemy){
            if(enemy->getcamp()!=this->camp){
                has_target=1;
                enemy->bleed(atk);
                return;
            }
        }
    }
    has_target=0;
}

BattleUnit::~BattleUnit()
{

}
