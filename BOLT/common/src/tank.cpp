#include "tank.h"
#include <iostream>
#include <QPainter>
#include <QKeyEvent>


Tank::Tank(int life,int movementSpeed)
    :_life(life),_movementSpeed(movementSpeed)
 {

}
QRectF Tank::boundingRect() const
{
    return QRectF(-50, -50,100,75);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(-50, -50,100,75);
    return path;
}
void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    QColor red(200,0,50);
    painter->setBrush(red);
    painter->drawRect(-50, -50,100,50);
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
}

void Tank::advance(int step)
{


    if (!step)
    {
        return;
    }

    if(!this->hasFocus()){
        this->setFocus();
    }
}

