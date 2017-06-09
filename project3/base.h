#ifndef BASE_H
#define BASE_H

#include <QObject>
#include<QPointF>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<battleunit.h>

class Base : public BattleUnit
{
    Q_OBJECT
public:
    explicit Base(bool camp, QObject *parent = 0);
    void bleed(int dmg);

signals:

public slots:
    void detect();
    void attack();

private:
    QPointF atk_dest;

};

#endif // BASE_H
