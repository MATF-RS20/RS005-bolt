#include "igrica1.hpp"
#include "ui_igrica1.h"
#include "lopta.hpp"

#include <QTimer>
#include <QDebug>

Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Igrica1)
{
    ui->setupUi(this);

    setWindowTitle("Bolt - Igrica 1");
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
    int x = ui->graphicsView->geometry().x();
    int y = ui->graphicsView->geometry().y();

    int width = ui->graphicsView->geometry().width();
    int height= ui->graphicsView->geometry().height();

    scene->setSceneRect(x, y, width, height);

    // Dodajemo scenu na view
    ui->graphicsView->setScene(scene);

    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Ukljucujemo anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    ui->graphicsView->setStyleSheet("background-image: url(:/images/g1.jpg);");

    Lopta *lopta = new Lopta(50, 1);
    lopta->setPos(0, 0);
    scene->addItem(lopta);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer.start(1000/33);
}
