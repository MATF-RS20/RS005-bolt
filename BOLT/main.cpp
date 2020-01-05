#include "bolt.hpp"
#include <iostream>
#include <QtGui>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bolt w;
    w.show();

    return a.exec();
}
