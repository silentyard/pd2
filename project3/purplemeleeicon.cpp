#include "purplemeleeicon.h"
#include "graphicsview.h"

extern graphicsView *w;
purplemeleeicon::purplemeleeicon()
{
    setPixmap(QPixmap(":/image/purplemeleeicon.png").scaled(80,80));
}

void purplemeleeicon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=2){
        w->setCursorPixmap(":/image/purplemelee.png");
        w->build =2;
    }
}
