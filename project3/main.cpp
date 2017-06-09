#include "graphicsview.h"
#include <QApplication>

graphicsView *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new graphicsView();
    w->show();

    return a.exec();
}
