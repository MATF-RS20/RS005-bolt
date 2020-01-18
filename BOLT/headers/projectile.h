#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsItem>

class Projectile:public QGraphicsItem
{
public:
    Projectile(bool isTank =true,int _speed=7);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    void advance(int step) override;


private:
    int _speed;
//    int _direction;
    bool _isTenk;

};

#endif // PROJECTILE_H
