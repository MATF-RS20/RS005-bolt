#include "headers/tank.h"
#include <iostream>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

Tank::Tank(int life,int movementSpeed)
    :_life(life),_movementSpeed(movementSpeed)
{

}

QRectF Tank::boundingRect() const
{
    return QRectF(-50, -50, 100, 75);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(-50, -50,100,75);
    return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)

    QColor red(200,0,50);
    painter->setBrush(red);
    painter->drawRect(-50, -50,100,50);
}

void Tank::keyPressEvent(QKeyEvent * event){

    if (event->key() == Qt::Key_Left and x()-_movementSpeed>50){
        setPos(x()-_movementSpeed,y());
    }
    else if (event->key() == Qt::Key_Right and x()+_movementSpeed<850){
        setPos(x()+_movementSpeed,y());
    }
    if(event->key() == Qt::Key_Space){
            fire();
    }
    event->setAccepted(true);
 //   update();
}

void Tank::advance(int step)
{

    if (!step) {
        auto list = this->scene()->collidingItems(this);
        if(!list.isEmpty()){
          //  delete list[0];
            delete this;
        }
        return;
    }
    else{
    if(!this->hasFocus()){
        this->setFocus();
    }
    }

}
