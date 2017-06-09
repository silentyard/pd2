#ifndef PURPLESIEGEICON_H
#define PURPLESIEGEICON_H

#include<QGraphicsPixmapItem>
#include<QMouseEvent>

class purplesiegeicon: public QGraphicsPixmapItem
{
public:
    purplesiegeicon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PURPLESIEGEICON_H
