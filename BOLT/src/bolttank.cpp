#include "headers/bolttank.hpp"
#include "headers/projectile.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>
#include "boltprojectile.hpp"

BoltTank::BoltTank()
    :_tankWidth(120), _tankHeigth(70), _movementSpeed(10)
{

}
QRectF BoltTank::boundingRect() const
{
    return QRectF(0, 0, _tankWidth, _tankHeigth);
}

QPainterPath BoltTank::shape() const
{
    QPainterPath path;

    path.addRect(0, 0, _tankWidth, _tankHeigth);

    return path;
}

void BoltTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

//    painter->setBrush(Qt::green);
//    painter->drawRect(boundingRect());
//    painter->setBrush(Qt::blue);
//    painter->drawPath(shape());

    //Crtanje topa
    painter->drawPixmap(0, 0, _tankWidth, _tankHeigth, QPixmap(":/images/top.png"));


}
void BoltTank::keyPressEvent(QKeyEvent * event){

    if (event->key() == Qt::Key_Left and x()-_movementSpeed>-5){
        setPos(x()-_movementSpeed,y());
    }
    else if (event->key() == Qt::Key_Right and x()+_movementSpeed<790){
        setPos(x()+_movementSpeed,y());
    }else if(event->key() == Qt::Key_Space){
        fire();
    }
    event->setAccepted(true);
 //   update();
}
void BoltTank::fire(){
    BoltProjectile* bolt=new BoltProjectile();
    bolt->setPos(x()+_tankWidth/2,y()+_tankHeigth);
    this->scene()->addItem(bolt);
}
