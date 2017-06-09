#include "melee.h"
#include<qmath.h>
#include<QDebug>
#include<QBrush>
#include<QPen>
#include<QGraphicsScene>

melee::melee(bool camp, int initx,QGraphicsItem *parent):
    BattleUnit(camp,initx,atk=20,max_hp=160,speed=5,30,size=70)
{
    if(camp==1){
        setPixmap(QPixmap(":/image/bluemelee.png").scaled(70,70));
    }
    else{
        setPixmap(QPixmap(":/image/purplemelee.png").scaled(70,70));
    }
}

