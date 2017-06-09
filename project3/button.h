#ifndef BUTTON_H
#define BUTTON_H
#include<QGraphicsTextItem>
#include<QString>

class Button: public QGraphicsTextItem
{
public:
    Button(QString title);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QString title;
};

#endif // BUTTON_H
