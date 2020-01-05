#ifndef LOPTA_HPP
#define LOPTA_HPP

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QPoint>

class Lopta : public QGraphicsEllipseItem
{
public:
    Lopta();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // LOPTA_HPP
