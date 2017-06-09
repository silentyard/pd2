#include "bluesiegeicon.h"
#include"graphicsview.h"
#include<QDebug>

extern graphicsView *w;
bluesiegeicon::bluesiegeicon()
{
    setPixmap(QPixmap(":/image/bluesiegeicon.png").scaled(80,80));
}

void bluesiegeicon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=5){
        w->setCursorPixmap(":/image/bluesiege.png");
        w-> build =5;
    }
}
