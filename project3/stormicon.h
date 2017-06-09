#ifndef STORMICON_H
#define STORMICON_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>

class StormIcon: public QGraphicsPixmapItem
{
public:
    StormIcon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // STORMICON_H
