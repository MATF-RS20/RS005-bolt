#include "headers/igrica3.hpp"
#include "ui_igrica1.h"
#include "headers/invader.h"
#include "headers/invadertank.h"
#include <QTimer>
#include "headers/tank.h"
#include <QGraphicsScene>
#include <QGraphicsView>

Igrica3::Igrica3(QWidget *parent) :
    QWidget(parent), ui(new Ui::Igrica1)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setSceneRect(0,0,900,600);
    scene->setSceneRect(0,0,900,600);
    setFixedSize(900+5,600+5);

    // Dodajemo scenu na view
    ui->graphicsView->setScene(scene);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Ukljucujemo anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    setStyleSheet("background-image: url(:/images/g1.jpg);");
    invader* i=new invader();
    i->setPos(400,50);
    scene->addItem(i);
    InvaderTank *tank = new InvaderTank();
    tank->setPos(400,600);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/100);  //postavljamo na 100 fps

}

Igrica3::~Igrica3()
{
    delete ui;
}
