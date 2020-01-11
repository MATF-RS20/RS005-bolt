#include "igrica1.hpp"
#include "ui_igrica1.h"
#include "lopta.hpp"

#include <QTimer>
#include <QDebug>
//#include <QRandomGenerator>

Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent), ui(new Ui::Igrica1),
    windowWidth(900), windowHeight(600)
{
    ui->setupUi(this);

    setWindowTitle("Bolt - Igrica 1");

    /* Velicinu prozora stavljam u promenljivu,
     * da bi velicina view-a i scene mogla da prati velicinu prozor.*/
    setFixedSize(windowWidth+5,windowHeight+5);
    move(250, 750);

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
    ui->graphicsView->setSceneRect(0, 0, windowWidth, windowHeight);
    scene->setSceneRect(0, 0, windowWidth, windowHeight);

    // Dodajemo scenu na view
    ui->graphicsView->setScene(scene);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Ukljucujemo anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    ui->graphicsView->setStyleSheet("background-image: url(:/images/g1.jpg);");

    Lopta *lopta = new Lopta(50, 1);
    scene->addItem(lopta);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/150);  //postavljamo na 150 fps
}
