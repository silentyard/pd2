#ifndef BLUESUPERICON_H
#define BLUESUPERICON_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>

class bluesupericon: public QGraphicsPixmapItem
{
public:
    bluesupericon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BLUESUPERICON_H
