#ifndef LOPTA_HPP
#define LOPTA_HPP

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>

class Objekat : public QGraphicsItem
{
public:
    /* Loptu pozivamo sa dimenzijom zeljenog precnika i podatkom za koju igricu se crta,
     * zbog primene konkretne animacije te lopte */
    Objekat(int radius, int igrica);

    int getRadius();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void keyPressEvent(QKeyEvent *event) override;

protected:
    void advance(int step) override;

private:
    int radius;
    int igrica;     // Vrednost: 1,2,3. Podatak koji nam ukazuje na to koja je igrica trenutno pokrenuta

    /*Smerovi u kojima se lopta krece*/
    int directionX;
    int directionY;
};

#endif // LOPTA_HPP
