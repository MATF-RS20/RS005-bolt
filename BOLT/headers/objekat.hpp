#ifndef LOPTA_HPP
#define LOPTA_HPP
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>

class Objekat : public QObject,public QGraphicsItem
{
    Q_OBJECT

public:
    /* Loptu pozivamo sa dimenzijom zeljenog precnika i podatkom za koju igricu se crta,
     * zbog primene konkretne animacije te lopte */
    Objekat(int radius);
    virtual ~Objekat() override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void keyPressEvent(QKeyEvent *event) override;

    static int brojLopti;

    int getRadius();
    int getDirectionX();
    int getDirectionY();
    void setDirectionX(int x);
    void setDirectionY(int y);

signals:
    void loptaPogodjena(qreal x, qreal y, int radijus);
    void krajIgre(bool tenkUnisten );
    void pobeda();

protected:
    void advance(int step) override;

private:
    int _radius;
    /*Smerovi u kojima se lopta krece*/
    int _directionX;
    int _directionY;
};

#endif // LOPTA_HPP
