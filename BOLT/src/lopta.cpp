#include "headers/lopta.hpp"

#include <QDebug>

Lopta::Lopta(int radius, int igrica)
    : radius(radius), igrica(igrica),
      directionX(5), directionY(5)
{
    //setSelected(true);

    setPos(450,100);
}

void Lopta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPoint(0, 0), radius, radius);
}

QRectF Lopta::boundingRect() const
{
    return QRectF(-radius-2, -radius-2, radius*2+4 , radius*2+4);
}

QPainterPath Lopta::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0,0), radius, radius);
    return path;
}

void Lopta::advance(int step)
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

int Lopta::getRadius()
{
    return radius;
}

void Lopta::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Right:
            moveBy(10, 10);
            break;
    }

    update();
}
