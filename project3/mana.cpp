#include "mana.h"
#include<QFont>

mana::mana(): num(0)
{
    setPlainText(QString("mana:")+QString::number(num));
    setDefaultTextColor(Qt::black);
    setFont(QFont("time",16));
}

int mana::getnum(){
    return num;
}

int mana::setnum(int value)
{
    num -= value;
    setPlainText(QString("mana:")+QString::number(num));
}

void mana::increase(){
    if(num<10)
        num++;
    setPlainText(QString("mana:")+QString::number(num));
}
