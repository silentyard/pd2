#ifndef SUPER_H
#define SUPER_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QVector>
#include<QPointF>
#include<QTimer>

#include"battleunit.h"

class super : public BattleUnit
{
    Q_OBJECT
public:
    explicit super(bool camp,int initx,QObject *parent = 0);
};

#endif // SUPER_H
