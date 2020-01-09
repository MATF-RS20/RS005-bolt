#include "lopta.hpp"

#include <QDebug>

Lopta::Lopta(int radius, int igrica)
    : radius(radius), igrica(igrica)
{

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
    return QRectF(0,0,50,50);
}

QPainterPath Lopta::shape() const
{
    QPainterPath path;
    path.addEllipse(-25, -25, 25, 25);
    return path;
}

void Lopta::advance(int step)
{
    if (!step)
        return;
    //Razdvajam definisanje kretanja loptice u zavisnosti od izbora igrice
    if (igrica == 1) {
        //DUSICA
    }

    else if (igrica == 2) {
        // NEVENA
    }

    else if (igrica == 3) {
        // JOVANA
    }
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
