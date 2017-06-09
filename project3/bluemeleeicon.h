#ifndef BLUEMELEEICON_H
#define BLUEMELEEICON_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>

class bluemeleeicon:public QGraphicsPixmapItem
{
public:
    bluemeleeicon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BLUEMELEEICON_H
