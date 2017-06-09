#include "purplecastericon.h"
#include "graphicsview.h"

extern graphicsView *w;
purplecastericon::purplecastericon()
{
    setPixmap(QPixmap(":/image/purplecastericon.png").scaled(80,80));
}

void purplecastericon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=4){
        w->setCursorPixmap(":/image/purplecaster.png");
        w->build =4;
    }
}
