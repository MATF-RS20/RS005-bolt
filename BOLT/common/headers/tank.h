#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>

class Tank:public QGraphicsItem
{
public:

    Tank(int life=3,int movementSpeed=10, int igrica=1, int tankWidth=70, int tankHeight=150);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void keyPressEvent(QKeyEvent * event) override;
    void advance(int step) override;
    void virtual fire() = 0;
//    void virtual fire();

private:
    int _life;
    int _movementSpeed;
    int _igrica;     // Vrednost: 1,2,3. Podatak koji nam ukazuje na to koja je igrica trenutno pokrenuta
    int _tankWidth;
    int _tankHeigth;
};

#endif // TANK_H
