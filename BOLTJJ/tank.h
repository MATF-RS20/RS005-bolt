#include <QGraphicsItem>

#ifndef TANK_H
#define TANK_H


class Tank:public QGraphicsItem
{
public:
    Tank();


    QRectF boundingRect() const override;


    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    void keyPressEvent(QKeyEvent * event) override;
    void advance(int step) override;
};

#endif // TANK_H
