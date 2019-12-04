#include "bolt.h"

#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bolt w;

    // Inicijalizujemo scenu
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // Kreiramo pogled za scenu
    QGraphicsView view(&scene);

    // Ukljucujemo anti-aliasing
    view.setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    view.setStyleSheet("background-image: url(:/images/g1.jpg);");

    view.resize(1000, 605);

    view.show();
    return a.exec();
}
