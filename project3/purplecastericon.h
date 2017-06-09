#ifndef PURPLECASTERICON_H
#define PURPLECASTERICON_H

#include<QGraphicsPixmapItem>
#include<QMouseEvent>

class purplecastericon: public QGraphicsPixmapItem
{
public:
    purplecastericon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PURPLECASTERICON_H
