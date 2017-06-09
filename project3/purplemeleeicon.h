#ifndef PURPLEMELEEICON_H
#define PURPLEMELEEICON_H

#include<QGraphicsPixmapItem>
#include<QMouseEvent>

class purplemeleeicon: public QGraphicsPixmapItem
{
public:
    purplemeleeicon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PURPLEMELEEICON_H
