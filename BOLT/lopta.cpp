#include "lopta.hpp"

Lopta::Lopta()
{

}

void Lopta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPoint(0, 0), 100, 100);

}

QRectF Lopta::boundingRect() const
{
    return QRectF(0,0,100,100);
}
