#ifndef HERO_H
#define HERO_H

#include <QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QObject>

#include<QTimer>

class Hero: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hero();
    void attack();
    ~Hero();
public slots:
    void downcount();
    void bulletfly();
private:
    QTimer *timer;
    QTimer *b_timer;
    QGraphicsRectItem *max_power;
    QGraphicsRectItem *current_power;
    QGraphicsPixmapItem *bullet;
    double count;
};

#endif // HERO_H
