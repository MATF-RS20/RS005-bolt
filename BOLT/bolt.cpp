#include "bolt.h"
#include "ui_bolt.h"

Bolt::Bolt(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Bolt)
{

    ui->setupUi(this);

    instructions();

//    // Inicijalizujemo scenu
//    QGraphicsScene scene;
//    scene.setSceneRect(-300, -300, 800, 400);

//    // Iskljucujemo indeksiranje pozicija elemenata scene
//    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

//    // Kreiramo pogled za scenu
//    QGraphicsView view(&scene);

//    // Ukljucujemo anti-aliasing
//    view.setRenderHint(QPainter::Antialiasing);

//    /*/ Postavljamo sliku za pozadinu
//    view.setStyleSheet("background-image: url(:/images/g1.jpg);"); */

//    view.show();
}


Bolt::~Bolt()
{

}


void Bolt::instructions() {
    qDebug() <<"Pokreni animaciju dugmetom G, pauziraj dugmetom P.";
    qDebug() <<"Za kretanje tenka koristiti strelice na levo i na desno.";
    qDebug() << "Za ispaljivanje munje koristi SPACE dugme na tastaturi.";
}
