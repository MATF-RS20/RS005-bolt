#ifndef LOPTA_HPP
#define LOPTA_HPP

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QKeyEvent>
#include <QPoint>

class Lopta : public QGraphicsEllipseItem
{
public:
    Lopta(int radius, int igrica);
    /* Loptu pozivamo sa dimenzijom zeljenog precnika i podatkom za koju igricu se crta,
     * zbog primene konkretne animacije te lopte */
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void advance(int step) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    int radius;
    int igrica;     // Vrednost: 1,2,3. Podatak koji nam ukazuje na to koja je igrica trenutno pokrenuta
};

#endif // LOPTA_HPP
