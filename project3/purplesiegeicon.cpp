#include "purplesiegeicon.h"
#include "graphicsview.h"

extern graphicsView *w;
purplesiegeicon::purplesiegeicon()
{
    setPixmap(QPixmap(":/image/purplesiegeicon.png").scaled(80,80));
}

void purplesiegeicon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=6){
        w->setCursorPixmap(":/image/purplesiege.png");
        w->build =6;
    }
}
