#include "bolt.h"
#include <iostream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bolt w;
    w.show();

    return a.exec();
}
