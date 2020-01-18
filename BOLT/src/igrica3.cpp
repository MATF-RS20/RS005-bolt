#include "headers/igrica3.hpp"
#include "ui_igrica1.h"
#include "headers/invader.h"
#include "headers/invadertank.h"
#include <QTimer>
#include "headers/tank.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QTime>
void Igrica3::setValue()
{
    auto list = scene->items();
    if(list.size()==1)
        //reset igrice
        delete list[0];
}
Igrica3::Igrica3(QWidget *parent) :
    QWidget(parent), ui(new Ui::Igrica1)
{
    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
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
    setStyleSheet("background-image: url(:/images/mushrooms.jpg);");
 //   invader* i=new invader();
  //  i->setPos(400,50);
    //scene->addItem(i);
    InvaderTank *tank = new InvaderTank();
    tank->setPos(400,600);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    for (auto i = 1; i < 3; ++i)
    {
        for(auto j= 1; j <8; j++){
            invader * inv = new invader();
            inv->setPos(j*60,
                      i*100);
              scene->addItem(inv);
        }
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer,SIGNAL (timeout()),
                        this, SLOT(setValue()));
    timer->start(1000/100);


}

Igrica3::~Igrica3()
{
    delete ui;
}
