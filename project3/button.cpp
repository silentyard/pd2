#include "button.h"
#include<QFont>
#include<QTimer>
#include<graphicsview.h>

extern graphicsView *w;
Button::Button(QString title):title(title)
{
    setPlainText(title);
    setDefaultTextColor(Qt::black);
    setFont(QFont("time",25));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(title==QString("Start")){
        w->play();
        w->setScene(w->scene);
        w->game_timer->start(1000);
        w->gametime=0;
    }

    if(title==QString("Back"))
        w->setScene(w->homepage);

    if(title==QString("Rank"))
        w->setScene(w->ranking);
}
