#include <iostream>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include "headers/invader.h"
invader::invader()
{

}


QRectF invader::boundingRect() const
{
    return QRectF(-25, -25,50,50);
}

QPainterPath invader::shape() const
{
    QPainterPath path;
    path.addRect(-25, -25,50,50);
    return path;
}
void invader::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    QColor r(100,0,50);
    painter->setBrush(r);
    painter->drawRect(-25, -25,50,50);
}



void invader::advance(int step)
{

    if (!step)
    {

        return;
    }


}
