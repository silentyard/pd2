#include "bluemeleeicon.h"
#include"graphicsview.h"
#include<QDebug>

extern graphicsView *w;
bluemeleeicon::bluemeleeicon()
{
    setPixmap(QPixmap(":/image/bluemeleeicon.png").scaled(80,80));
}

void bluemeleeicon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=1){
        w->setCursorPixmap(":/image/bluemelee.png");
        w-> build =1;
    }
}
