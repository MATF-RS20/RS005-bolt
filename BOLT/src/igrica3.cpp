#include "headers/igrica3.hpp"
#include "ui_igrica3.h"
#include "headers/invader.h"
#include "headers/invadertank.h"
#include <QTimer>
#include "headers/tank.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTime>
#include <QObject>
#include "headers/gameover.hpp"
#include "headers/gameoverinvader.h"
#include <QMediaPlayer>
#define ROW (3)

Igrica3::Igrica3(QWidget *parent,int invaderNumber) :
    QWidget(parent), ui(new Ui::Igrica3),
     _windowWidth(900), _windowHeight(600),
     _invaderSpeed(2),_invaderNumber(invaderNumber),
     _bingo(1)
{
    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setSceneRect(0, 0, _windowWidth, _windowHeight);
    scene->setSceneRect(0, 0, _windowWidth, _windowHeight);
    setFixedSize(_windowWidth+5,_windowHeight+5);

    ui->graphicsView->setScene(scene);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    setStyleSheet("background-image: url(:/images/mushrooms.jpg);");
    timer = new QTimer(this);
    InvaderTank *tank = new InvaderTank();
    tank->setPos(400,600);
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(tank);
    tank->setFocus();

    for (auto i = 1; i < ROW; ++i)
    {
        for(auto j= 1; j <_invaderNumber; j++){
            invader * inv = new invader(1,_invaderSpeed,_bingo);
            inv->setPos(j*60,
                      i*100);
              scene->addItem(inv);
        }
    }


    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer,SIGNAL (timeout()),
                        this, SLOT(checkState()));
    timer->start(1000/100);
    music->setMedia(QUrl("qrc:/music/Restricted-Zone_Looping.mp3"));
    music->play();
}

void Igrica3::checkState()
{
    auto list = scene->items();

    if(list.size()==1 ){
        _bingo+=10;
        _invaderNumber = std::min(++_invaderNumber,10);
        _invaderSpeed ++;
        //reset igrice
        for (auto i = 1; i < ROW; ++i)
        {
            for(auto j= 1; j <_invaderNumber; j++){
                invader * inv = new invader(1,_invaderSpeed);
                inv->setPos(j*60,i*100);
                scene->addItem(inv);
            }
        }
    }
    auto tankCheck = false;
    for(auto el : list){
        InvaderTank * tank =dynamic_cast<InvaderTank*>(el);
        if(tank)
            tankCheck =true;
    }

    if(music->state() == QMediaPlayer::StoppedState)
            music->play();

    if(!tankCheck){
        music->stop();
        GameOverInvader* w = new GameOverInvader();
        w->show();
        delete this;
     }
}
Igrica3::~Igrica3()
{
    delete ui;
}

