#include "headers/igrica1.hpp"
#include "ui_igrica1.h"
#include "headers/objekat.hpp"
#include "headers/bolttank.hpp"
#include "headers/invadertank.h"

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent), ui(new Ui::Igrica1),
    _windowWidth(900), _windowHeight(600)
{
    ui->setupUi(this);

    setWindowTitle("Bolt - Igrica 1");

    /* Velicinu prozora stavljam u promenljivu,
     * da bi velicina view-a i scene mogla da prati velicinu prozor.*/
    setFixedSize(_windowWidth+5,_windowHeight+5);
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
    ui->graphicsView->setSceneRect(0, 0, _windowWidth, _windowHeight);
    scene->setSceneRect(0, 0, _windowWidth, _windowHeight);

    // Dodajemo scenu na view
    ui->graphicsView->setScene(scene);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Ukljucujemo anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    setStyleSheet("background-image: url(:/images/pozadina.png);");

    Objekat *objLopta = new Objekat(60);
    scene->addItem(objLopta);

    BoltTank *tank = new BoltTank();
    tank->setPos(400,474);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/100);  //postavljamo na 100 fps
}

