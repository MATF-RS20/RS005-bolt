#include "headers/objekat.hpp"

#include <QDebug>

Objekat::Objekat(int radius)
    : _radius(radius),
      _directionX(5), _directionY(5)
{
    setPos(450,100);
    setZValue(1);
}

void Objekat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::red);
    if (!collidingItems(Qt::IntersectsItemShape).isEmpty()) {
        painter->setBrush(Qt::yellow);
    }
    painter->drawEllipse(QPoint(0, 0), _radius, _radius);
}

QRectF Objekat::boundingRect() const
{
    return QRectF(-_radius-2, -_radius-2, _radius*2+4 , _radius*2+4);
}

QPainterPath Objekat::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0,0), _radius, _radius);
    return path;
}

void Objekat::advance(int step)
{
    if (!step)
        return;
    //Razdvajam definisanje kretanja loptice u zavisnosti od izbora igrice

    moveBy(_directionX/2,_directionY/3);
    if(x() <= 0+_radius || x() >= 900-_radius){
        _directionX = -_directionX;
    }
    if(y() <= 0+_radius || y() >= 600-_radius){
        _directionY = -_directionY;
    }

}

int Objekat::getRadius()
{
    return _radius;
}

void Objekat::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Right:
            moveBy(10, 10);
            break;
    }

    update();
}
