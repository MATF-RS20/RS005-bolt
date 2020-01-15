#ifndef BOLTTANK_HPP
#define BOLTTANK_HPP

#include "tank.h"

class BoltTank: public Tank
{
public:
    BoltTank();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void keyPressEvent(QKeyEvent * event) override;

    void fire() override;

private:
    int _tankWidth;
    int _tankHeigth;
    int _movementSpeed;
    int _life;

};

#endif // BOLTTANK_HPP
