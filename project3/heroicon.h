#ifndef HEROICON_H
#define HEROICON_H
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QMouseEvent>

class HeroIcon: public QGraphicsPixmapItem
{
public:
    HeroIcon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void charge();

private:
    QGraphicsRectItem *max_power;
    QGraphicsRectItem *current_power;
    int power;
};

#endif // HEROICON_H
