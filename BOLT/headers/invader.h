#ifndef INVADER_H
#define INVADER_H


#include <QGraphicsItem>

class invader:public QGraphicsItem
{
public:
    invader(int sgn=1,int speedLevel=2,int bingo=10);

    QRectF boundingRect() const override;


    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    void advance(int step) override;
    void toBeDeleted();
private:
    int _sgn;
    int _speedLevel;
    int _bingo;
    bool _toBeDeleted = false;
};

#endif // INVADER_H
