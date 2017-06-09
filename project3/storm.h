#ifndef STORM_H
#define STORM_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsEllipseItem>
#include<QTimer>
#include<QLineF>

class Storm: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Storm();
    void shoot();

public slots:
    void move();
    void hit();

private:
    QGraphicsEllipseItem* range;
    QTimer* timer;
    QTimer* mv_timer;
    int dps;
    int count;

    QGraphicsPixmapItem *bullet;
    QLineF *trace;
};

#endif // STORM_H
