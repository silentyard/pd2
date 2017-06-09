#ifndef BLUECASTERICON_H
#define BLUECASTERICON_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>

class bluecastericon: public QGraphicsPixmapItem
{
public:
    bluecastericon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BLUECASTERICON_H
