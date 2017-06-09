#ifndef MELEE_H
#define MELEE_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QVector>
#include<QPointF>
#include<QTimer>
#include<battleunit.h>

class melee: public BattleUnit
{
    Q_OBJECT
public:
    melee(bool camp, int initx ,QGraphicsItem *parent=0);
};

#endif // MELEE_H
