#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include "headers/projectile.h"

class Tank:public QGraphicsItem
{
public:

    Tank(int life=3,int movementSpeed=10, int tankWidth=120, int tankHeight=70);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void keyPressEvent(QKeyEvent * event) override;
    void advance(int step) override;
    void virtual fire() = 0;

private:
    int _life;
    int _movementSpeed;
    int _tankWidth;
    int _tankHeigth;
};

#endif // TANK_H
