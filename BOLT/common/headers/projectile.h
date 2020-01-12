#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsItem>

class projectile:public QGraphicsItem
{
public:
    projectile();
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
