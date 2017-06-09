#ifndef MANA_H
#define MANA_H

#include <QObject>
#include<QGraphicsTextItem>

class mana: public QGraphicsTextItem
{
    Q_OBJECT
public:
    mana();
    int getnum();
    int setnum(int value);
public slots:
    void increase();
private:
    int num;
};

#endif // MANA_H
