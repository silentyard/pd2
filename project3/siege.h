#ifndef SIEGE_H
#define SIEGE_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QVector>
#include<QPointF>
#include<QTimer>

#include"battleunit.h"


class siege : public BattleUnit
{
    Q_OBJECT
public:
    explicit siege(bool camp,int initx,QObject *parent = 0);
};

#endif // SIEGE_H
