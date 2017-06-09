#ifndef BATTLEUNIT_H
#define BATTLEUNIT_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QVector>
#include<QPointF>
#include<QTimer>

class BattleUnit: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BattleUnit(bool camp,int initx,int atk,double max_hp,int speed,int range,int size
               ,QGraphicsItem *parent=0);
    void bleed(int dmg);
    bool getcamp();
    ~BattleUnit();

public slots:
    void move();
    void detect();

protected:
    bool camp;
    bool has_target;
    double max_hp;
    double hp;
    int atk;
    int speed;
    int point_index;
    int atk_dist;
    int size;
    QList<QPointF> move_path;
    QVector<QPointF> atk_range_points;
    QGraphicsPolygonItem *atk_range;
    QGraphicsRectItem *maxhp;
    QGraphicsRectItem *current_hp;

    QTimer *mv_timer;
    QTimer *atk_timer;

};

#endif // BATTLEUNIT_H
