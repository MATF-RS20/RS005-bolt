#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsItem>

class Projectile:public QGraphicsItem
{
public:
    Projectile();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    void advance(int step) override;


private:
    int _speed=7;
};

#endif // PROJECTILE_H
