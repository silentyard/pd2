#include "caster.h"
#include<qmath.h>
#include<QDebug>
#include<QBrush>
#include<QPen>
#include<QGraphicsScene>

caster::caster(bool camp, int initx,QGraphicsItem *parent):
    BattleUnit(camp,initx,atk=40,max_hp=80,speed=5,60,size=70)

{
    if(camp==1){
        setPixmap(QPixmap(":/image/bluecaster.png").scaled(70,70));
    }
    else{
        setPixmap(QPixmap(":/image/purplecaster.png").scaled(70,70));
    }
}
