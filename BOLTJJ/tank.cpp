#include "tank.h"
#include <iostream>
#include <QPainter>
#include <QKeyEvent>
Tank::Tank()
{

}
QRectF Tank::boundingRect() const
{
    return QRectF(-50, -50,100,75);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(-50, -50,100,50);
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
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }

}

void Tank::advance(int step)
{

    if (!step)
    {
        return;
    }


}

