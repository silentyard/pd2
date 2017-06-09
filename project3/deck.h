#ifndef DECK_H
#define DECK_H

#include<QMouseEvent>
#include<QGraphicsPixmapItem>
#include<QVector>
#include<QPointF>
#include<QObject>

class deck:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    deck(int camp);
    void refresh();
    void switchcard(int usage);
    QVector<int> all_card;
    QVector<int> on_deck;
    QVector<QPointF> pos;
    QVector<QGraphicsPixmapItem*> icons;

    //cant additem in ctor
private:
    bool camp;

};

#endif // DECK_H
