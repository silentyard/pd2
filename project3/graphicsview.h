#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include<QGraphicsView>
#include<QMouseEvent>
#include<QKeyEvent>

#include<QGraphicsPixmapItem>
#include<QGraphicsTextItem>
#include"mana.h"
#include"deck.h"
#include"hero.h"
#include"heroicon.h"

#include<QVector>

class graphicsView: public QGraphicsView
{
    Q_OBJECT
    public:
    graphicsView();
    void setCursorPixmap(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *key);

    void showranking();
    void play();

    int build;

    QGraphicsScene *scene;
    QGraphicsScene *summary;
    QGraphicsScene *homepage;
    QGraphicsScene *ranking;
    int gametime;
    QVector<int> rktime;
    QTimer *game_timer;

    deck *bluedeck; //temp
    Hero *baron;
    HeroIcon *icon;

    ~graphicsView();

public slots:
    void purpleAI();
    void counting();

private:
    QTimer *timer;
    QTimer *ai_timer;
    QGraphicsTextItem  *showtime;
    QGraphicsPixmapItem *cursor;
    mana *bluemana;
    mana *purplemana;
    deck *purpledeck;
};

#endif // GRAPHICSVIEW_H
