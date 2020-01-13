#include "headers/objekat.hpp"

#include <QDebug>

Objekat::Objekat(int radius, int igrica)
    : radius(radius), igrica(igrica),
      directionX(5), directionY(5)
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
    painter->drawEllipse(QPoint(0, 0), radius, radius);
}

QRectF Objekat::boundingRect() const
{
    return QRectF(-radius-2, -radius-2, radius*2+4 , radius*2+4);
}

QPainterPath Objekat::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0,0), radius, radius);
    return path;
}

void Objekat::advance(int step)
{
    if (!step)
        return;
    //Razdvajam definisanje kretanja loptice u zavisnosti od izbora igrice
    if (igrica == 1) {
        //DUSICA
        moveBy(directionX/2,directionY/3);
        if(x() <= 0+radius || x() >= 900-radius){
            directionX = -directionX;
        }
        if(y() <= 0+radius || y() >= 600-radius){
            directionY = -directionY;
        }
    }

    else if (igrica == 2) {
        // NEVENA
    }

    else if (igrica == 3) {
        // JOVANA
    }
}

int Objekat::getRadius()
{
    return radius;
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
