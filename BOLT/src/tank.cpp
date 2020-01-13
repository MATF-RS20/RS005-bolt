#include "headers/tank.h"
#include <iostream>
#include <QPainter>
#include <QKeyEvent>


Tank::Tank(int life,int movementSpeed, int igrica, int tankWidth, int tankHeigth)
    :_life(life),_movementSpeed(movementSpeed), _igrica(igrica),
      _tankWidth(tankWidth), _tankHeigth(tankHeigth)
{
    setPos(400, 450);
}

QRectF Tank::boundingRect() const
{
    if(_igrica == 3){
        return QRectF(-50, -50, _tankWidth, _tankHeigth);
    }
    return QRectF(0, 0, _tankWidth, _tankHeigth);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    if(_igrica == 1){
         path.addRect(0, 0, _tankWidth, _tankHeigth);
    }else if(_igrica == 3){
         path.addRect(-50, -50, _tankWidth, _tankHeigth);
    }

    return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

//    painter->setBrush(Qt::green);
//    painter->drawRect(boundingRect());
//    painter->setBrush(Qt::blue);
//    painter->drawPath(shape());

    // DUSICA - tenk
    if (_igrica == 1) {
        painter->drawPixmap(0, 0, _tankWidth, _tankHeigth, QPixmap(":/images/tenk.png"));
    }

    // NEVENA - tenk
    else if (_igrica == 2) {

    }

    // JOVANA - tenk
    else {
        QColor red(200,0,50);
        painter->setBrush(red);
        painter->drawRect(-50, -50,100,50);
    }
}

void Tank::keyPressEvent(QKeyEvent * event){

//    if (event->key() == Qt::Key_Left)
//        moveBy(20, 20);

    if (event->key() == Qt::Key_Left and x()-_movementSpeed>-250){
        setPos(x()-_movementSpeed,y());
    }
    else if (event->key() == Qt::Key_Right and x()+_movementSpeed<250){
        setPos(x()+_movementSpeed,y());
    }else if(event->key() == Qt::Key_Space){
        fire();
    }
    event->setAccepted(true);
//   update();
}

void Tank::advance(int step)
{
    if (!step) {
        return;
    }

    if(!this->hasFocus()){
        this->setFocus();
    }
}

void Tank::fire()
{
    Projectile *t = new Projectile();
    t->setPos(x(),y()-37.5);
    // TODO
}

