#include "igrica1.hpp"
#include "ui_igrica1.h"
#include "lopta.hpp"


Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Igrica1)
{
    ui->setupUi(this);

    setWindowTitle("BOLT - Igrica 1");
    resize(900, 600);
    move(300, 100);

    pokreniIgricu();
}

Igrica1::~Igrica1()
{
    delete ui;
}

void Igrica1::pokreniIgricu()
{
    scene = new QGraphicsScene(this);

    // Inicijalizujemo scenu
    scene->setSceneRect(0, 0, 800, 400);

    // Dodajemo scenu na view
    ui->graphicsView->setScene(scene);

    // Iskljucujemo indeksiranje pozicija elemenata scene
//    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


    // Ukljucujemo anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    ui->graphicsView->setStyleSheet("background-image: url(:/images/g1.jpg);");

    Lopta *lopta = new Lopta();
    lopta->setPos(100, 100);

    scene->addItem(lopta);
}
