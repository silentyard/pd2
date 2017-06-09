#include "bluecastericon.h"
#include"graphicsview.h"
#include<QDebug>

extern graphicsView *w;
bluecastericon::bluecastericon()
{
    setPixmap(QPixmap(":/image/bluecastericon.png").scaled(80,80));
}

void bluecastericon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(w->build!=3){
        w->setCursorPixmap(":/image/bluecaster.png");
        w-> build =3;
    }
}
