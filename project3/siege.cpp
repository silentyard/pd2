#include "siege.h"
#include<qmath.h>
#include<QDebug>
#include<QBrush>
#include<QPen>
#include<QGraphicsScene>

siege::siege(bool camp, int initx,QObject *parent) :
    BattleUnit(camp,initx,atk=30,max_hp=400,speed=3,50,size=70)
{
    if(camp==1){
        setPixmap(QPixmap(":/image/bluesiege.png").scaled(70,70));
    }
    else{
        setPixmap(QPixmap(":/image/purplesiege.png").scaled(70,70));
    } 
}
