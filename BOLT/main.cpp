#include "bolt.h"
#include <iostream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

void instructions(){
    std::cout<<"Pokreni animaciju dugmetom G, pauziraj dugmetom P."<<std::endl;
    std::cout<<"Za kretanje tenka koristiti strelice na levo i na desno."<<std::endl;
    std::cout<<"Za ispaljivanje munje koristi SPACE dugme na tastaturi."<<std::endl;
}
int main(int argc, char *argv[])
{
    instructions();

    QApplication a(argc, argv);
    Bolt w;

    // Inicijalizujemo scenu
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 800, 400);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // Kreiramo pogled za scenu
    QGraphicsView view(&scene);

    // Ukljucujemo anti-aliasing
    view.setRenderHint(QPainter::Antialiasing);

    /*/ Postavljamo sliku za pozadinu
    view.setStyleSheet("background-image: url(:/images/g1.jpg);"); */

    view.show();
    return a.exec();
}
