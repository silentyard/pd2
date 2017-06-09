#ifndef BLUESIEGEICON_H
#define BLUESIEGEICON_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>

class bluesiegeicon: public QGraphicsPixmapItem
{
public:
    bluesiegeicon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BLUESIEGEICON_H
