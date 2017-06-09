#ifndef PURPLESUPERICON_H
#define PURPLESUPERICON_H

#include<QGraphicsPixmapItem>
#include<QMouseEvent>

class purplesupericon:public QGraphicsPixmapItem
{
public:
    purplesupericon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PURPLESUPERICON_H
