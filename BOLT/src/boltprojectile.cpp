#include "headers/boltprojectile.hpp"
#include <QPainter>

BoltProjectile::BoltProjectile()
    : _pocX(-5), _pocY(-18), _boltWidth(10), _boltHeight(36)
{
    setZValue(1);
}

QRectF BoltProjectile::boundingRect() const
{
    return QRectF(_pocX,_pocY,_boltWidth,_boltHeight);
}

QPainterPath BoltProjectile::shape() const
{
    QPainterPath path;
    path.addRect(_pocX,_pocY,_boltWidth,_boltHeight);
    return path;
}

void BoltProjectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)

    painter->drawPixmap(_pocX, _pocY, _boltWidth, _boltHeight, QPixmap(":/images/b2.png"));
}
