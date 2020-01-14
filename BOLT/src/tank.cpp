#include "headers/tank.h"
#include <iostream>
#include <QPainter>
#include <QKeyEvent>


Tank::Tank(int life,int movementSpeed, int tankWidth, int tankHeigth)
    :_life(life),_movementSpeed(movementSpeed),
      _tankWidth(tankWidth), _tankHeigth(tankHeigth)
{}

QRectF Tank::boundingRect() const
{

    //return QRectF(-50, -50, _tankWidth, _tankHeigth);
    return QRectF(0, 0, _tankWidth, _tankHeigth);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;

    path.addRect(0, 0, _tankWidth, _tankHeigth);

    //path.addRect(-50, -50, _tankWidth, _tankHeigth);

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

    painter->drawPixmap(0, 0, _tankWidth, _tankHeigth, QPixmap(":/images/top.png"));


    // JOVANA - tenk

     // QColor red(200,0,50);
     // painter->setBrush(red);
    //  painter->drawRect(-50, -50,100,50);
}

void Tank::keyPressEvent(QKeyEvent * event){

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
