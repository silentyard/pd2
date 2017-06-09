#include "super.h"
#include<qmath.h>
#include<QDebug>
#include<QBrush>
#include<QPen>
#include<QGraphicsScene>

super::super(bool camp, int initx,QObject *parent) :
    BattleUnit(camp,initx,atk=15,max_hp=800,speed=2,40,size=70)
{
    if(camp==1){
        setPixmap(QPixmap(":/image/bluesuper.png").scaled(80,80));
    }
    else{
        setPixmap(QPixmap(":/image/purplesuper.png").scaled(70,70));
    }
}
