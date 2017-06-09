#include "purplesupericon.h"
#include "graphicsview.h"

extern graphicsView *w;
purplesupericon::purplesupericon()
{
    setPixmap(QPixmap(":/image/purplesupericon.png").scaled(80,80));
}

void purplesupericon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=8){
        w->setCursorPixmap(":/image/purplesuper.png");
        w->build =8;
    }
}
