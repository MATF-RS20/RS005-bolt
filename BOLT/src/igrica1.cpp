#include "headers/igrica1.hpp"
#include "ui_igrica1.h"
#include "headers/objekat.hpp"
#include "headers/bolttank.hpp"
#include "headers/invadertank.h"



#include <QMainWindow>
#include <QTimer>

//
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

    //Kreiram prvu Loptu
    Objekat *objLopta = new Objekat(60);
    scene->addItem(objLopta);

    //Kreiram tenk
    BoltTank *tank = new BoltTank();
    tank->setPos(400,474);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    //Postavljam tajmer za kretanje lopte
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/100);  //postavljamo na 100 fps

    //Postavljam tajmer da bih testirala kreiranje 2 lopte
    QTimer *timer2 = new QTimer(this);
    qDebug()<<objLopta->getX()<< " , "<<objLopta->getY();
    connect(timer2, SIGNAL(timeout()), this, SLOT(napraviNoveLopte(objLopta->getX(), objLopta->getY())));
    timer2->start(1000);
    // FALI dva: connect() sa    napraviNoveLopte() i zavrsiIgru()
}


void Igrica1::napraviNoveLopte(int x, int y)
{
    qDebug()<<x<< " ,,, "<<y;
    //Lopte trenutno crtam na proizvoljnoj lokaciji finalno ce to biti koordinate lopte koja je unistena
    Objekat* lopta1 = new Objekat(40);
    lopta1->setPos(x, y);
    Objekat* lopta2 = new Objekat(40);

    lopta2->setDirectionX(-lopta2->getDirectionX());
    lopta2->setPos(x, y);

    scene->addItem(lopta1);
    scene->addItem(lopta2);

    Objekat* lopta11 = new Objekat(40);
    lopta11->setPos(300, 300);
    Objekat* lopta22 = new Objekat(40);

    lopta22->setDirectionX(-lopta22->getDirectionX());
    lopta22->setPos(300, 300);

    scene->addItem(lopta11);
    scene->addItem(lopta22);

//Da bismo imali sledeci nivo razbijanja moramo povezati preko signala i slotova

//    connect(lopta1, loptaPogodjena, this, napraviNoveLopte());
//    connect(lopta2, loptaPogodjena, this, napraviNoveLopte());
}

void Igrica1::zavrsiIgru()
{
    qDebug() << "zavrsiIgru()";
    //_gameOver_ui = new GameOver();
    close();
    //_gameOver_ui->show();
}
