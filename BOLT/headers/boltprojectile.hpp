#ifndef BOLTPROJECTILE_HPP
#define BOLTPROJECTILE_HPP

#include "headers/projectile.h"
#include <QGraphicsItem>

class BoltProjectile: public Projectile
{
public:
    BoltProjectile();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
private:
    int _pocX;
    int _pocY;
    int _boltWidth;
    int _boltHeight;

};

#endif // BOLTPROJECTILE_HPP
