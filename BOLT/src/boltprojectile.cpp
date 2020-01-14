#include "headers/boltprojectile.hpp"
#include <QPainter>

BoltProjectile::BoltProjectile()
    : _pocX(-10), _pocY(-30), _boltWidth(20), _boltHeight(60)
{

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

    painter->drawPixmap(_pocX, _pocY, _boltWidth, _boltHeight, QPixmap(":/images/bolt.png"));
//    painter->drawRect(_pocX,_pocY,_boltWidth,_boltHeight);
}
