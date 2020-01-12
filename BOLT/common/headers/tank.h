#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>

class Tank:public QGraphicsItem
{
public:

    Tank(int life=3,int movementSpeed=10);


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
};

#endif // TANK_H
