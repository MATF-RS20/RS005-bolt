#ifndef INVADER_H
#define INVADER_H


#include <QGraphicsItem>

class invader:public QGraphicsItem
{
public:
    invader();

    QRectF boundingRect() const override;


    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    void advance(int step) override;
};

#endif // INVADER_H
