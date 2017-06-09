#include "basebullet.h"
#include<qmath.h>
#include<QTimer>

basebullet::basebullet():destroy_count(0)
{
    setPixmap(QPixmap(":/image/basebullet.png").scaled(50,50));
    QTimer *move_timer = new QTimer;
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(move_timer,SIGNAL(timeout()),this,SLOT(destroy()));
    move_timer->start(100);
}

void basebullet::move()
{
    int dist =  30;
    double deg = rotation();
    double dy = dist * qSin(qDegreesToRadians(deg));
    double dx = dist * qCos(qDegreesToRadians(deg));
    setPos(x()+dx,y()+dy);
}

void basebullet::destroy(){
    destroy_count+=1;
    if(destroy_count>5)
        delete this;
}
