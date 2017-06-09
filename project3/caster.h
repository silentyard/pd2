#ifndef CASTER_H
#define CASTER_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QVector>
#include<QPointF>
#include<QTimer>
#include"battleunit.h"

class caster:public BattleUnit
{
    Q_OBJECT
public:
    explicit caster(bool camp,int initx,QGraphicsItem *parent=0);
};

#endif // CASTER_H
