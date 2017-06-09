#include "bluesupericon.h"
#include"graphicsview.h"
#include<QDebug>

extern graphicsView *w;
bluesupericon::bluesupericon()
{
    setPixmap(QPixmap(":/image/bluesupericon.png").scaled(80,80));
}

void bluesupericon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=7){
        w->setCursorPixmap(":/image/bluesuper.png");
        w-> build =7;
    }
}
