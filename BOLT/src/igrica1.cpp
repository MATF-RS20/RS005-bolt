#include "headers/igrica1.hpp"
#include "ui_igrica1.h"
#include "headers/objekat.hpp"
#include "headers/bolttank.hpp"
#include "headers/gameover.hpp"
#include "headers/youwin.hpp"

#include <QMainWindow>
#include <QTimer>

#include <QDebug>

Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent), ui(new Ui::Igrica1),
    _windowWidth(900), _windowHeight(600)
{
    ui->setupUi(this);

    setWindowTitle("Bolt - Igrica 1");

    /* Postavljam fiksnu velicinu prozora i stavljam ih u promenljivu*/
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
    int velicinaPocetneLopte = 60;

    //Kreiram prvu Loptu velicine 60
    Objekat *objLopta = new Objekat(60);

    //Za x koordinatu pocetne lopte nasumicno biramo broj iz opsega (60,840)
    objLopta->setPos(velicinaPocetneLopte+qrand()%(_windowWidth-2*velicinaPocetneLopte),100);
    scene->addItem(objLopta);

    //Kreiram tenk
    BoltTank *tank = new BoltTank();
    tank->setPos(400,474);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    //Povezujemo preko signala i slotova crtanje novih loptica i kraj igre
    QObject::connect(objLopta,SIGNAL(loptaPogodjena(qreal,qreal,int)),
                     this, SLOT(napraviNoveLopte(qreal,qreal,int)));

    QObject::connect(objLopta,SIGNAL(krajIgre(bool)), this, SLOT(zavrsiIgru(bool)));
    QObject::connect(objLopta,SIGNAL(krajPobedom(bool)),this,SLOT(zavrsiPobedom(bool)));

    //Postavljam tajmer za kretanje lopte
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/100);  //postavljamo na 100 fps

}


void Igrica1::napraviNoveLopte(qreal x, qreal y, int r)
{
    int noviRadijus = r - 20  ;

    //Lopte crtam na koordinatama lopte koja je unistena
    Objekat* lopta1 = new Objekat(noviRadijus);
    lopta1->setPos(x, y);

    Objekat* lopta2 = new Objekat(noviRadijus);
    lopta2->setDirectionX(-lopta2->getDirectionX());
    lopta2->setPos(x, y);

    scene->addItem(lopta1);
    scene->addItem(lopta2);

    //Da bi i nove lopte imale sledeci nivo razbijanja
    QObject::connect(lopta1,SIGNAL(loptaPogodjena(qreal,qreal,int)),
                     this, SLOT(napraviNoveLopte(qreal,qreal,int)));

    QObject::connect(lopta2,SIGNAL(loptaPogodjena(qreal,qreal,int)),
                     this, SLOT(napraviNoveLopte(qreal,qreal,int)));

    //Da bi i nove lopte mogle da uniste tenk i zavrse igru i njih povezujemo
    QObject::connect(lopta1,SIGNAL(krajIgre(bool)),this,SLOT(zavrsiIgru(bool)));
    //QObject::connect(lopta1,SIGNAL(krajPobedom(bool)), this, SLOT(zavrsiPobedom(bool)));
    QObject::connect(lopta1,SIGNAL(krajPobedom(bool)),this,SLOT(zavrsiPobedom(bool)));

    QObject::connect(lopta2,SIGNAL(krajIgre(bool)),this,SLOT(zavrsiIgru(bool)));
    QObject::connect(lopta2,SIGNAL(krajPobedom(bool)), this, SLOT(zavrsiPobedom(bool)));
}

void Igrica1::zavrsiIgru(bool tenkUnisten)
{
    if(tenkUnisten){
        GameOver *_gameOver_ui;
        _gameOver_ui = new GameOver();
        close();

        _gameOver_ui->show();
    }
}

void Igrica1::zavrsiPobedom(bool lopteUnistene)
{
    if(lopteUnistene){
            YouWin *_win_ui;
            _win_ui = new YouWin();
            close();

            qDebug()<<"Pobeda";

            _win_ui->show();
        }
}

