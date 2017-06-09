#ifndef BASEBULLET_H
#define BASEBULLET_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>

class basebullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    basebullet();
public slots:
    void move();
    void destroy();

private:
    int destroy_count;
};

#endif  // BASEBULLET_H
