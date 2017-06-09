#include "stormicon.h"
#include"graphicsview.h"
#include"storm.h"

extern graphicsView *w;
StormIcon::StormIcon()
{
    setPixmap(QPixmap(":/image/stormicon.jpeg").scaled(80,80));
}

void StormIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(w->build!=9){
        w->setCursorPixmap(":/image/storm.png");
        w->build=9;
    }
}

