#include "headers/objekat.hpp"
#include "headers/boltprojectile.hpp"
#include "headers/bolttank.hpp"

#include <QDebug>
#include <QList>

Objekat::Objekat(int radius)
    : _radius(radius), _directionX(5), _directionY(5)
{
    brojLopti++;
    setZValue(1);
}

Objekat::~Objekat()
{
    brojLopti--;
}

int Objekat::brojLopti = 0;

void Objekat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(_radius<10){
        delete this; //Loptica je premalena pa je ne crtamo
    }

    //Postavljamo boju lopte razlicitu za svaki nivo
    painter->setBrush(Qt::red);

    if(_radius == 40){
       painter->setBrush(Qt::blue);
    }
      if(_radius == 20){
       painter->setBrush(Qt::green);
    }

    QList<QGraphicsItem*> collidedItems = collidingItems(Qt::IntersectsItemShape);

    if (!collidedItems.isEmpty()) {

        QGraphicsItem* item = collidedItems.first();
        BoltTank *tank = dynamic_cast<BoltTank*>(item);
        BoltProjectile *projectile = dynamic_cast<BoltProjectile*>(item);

        if (projectile) {       // Sudar lopte sa projektilom

            //Saljemo signal za pravljenje nove dve lopte jer je ova pogodjena
            emit loptaPogodjena(this->x(),this->y(),this->getRadius());
            brojLopti--;
            delete this;
            if(brojLopti == 1 ){
                qDebug()<<brojLopti;
                emit krajIgre(false);
            }
        }
        else if (tank) {        // Sudar lopte sa tenkom

            tank->setLife(tank->getLife()-1);

            if (tank->getLife() <= 0) {     // Kraj igre
                // posalji signal Igrici1 da se igra zavrsila i pozovi GameOver
                emit krajIgre(true);
            }
        } else {
            // Lopte se medjusobno sudaraju - IGNORISATI
        }
    }
    painter->drawEllipse(QPoint(0, 0), _radius, _radius);
}


QRectF Objekat::boundingRect() const
{
    return QRectF(-_radius-2, -_radius-2, _radius*2+4 , _radius*2+4);
}

QPainterPath Objekat::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0,0), _radius, _radius);
    return path;
}

void Objekat::advance(int step)
{
    if (!step)
        return;

    moveBy(_directionX/2,_directionY/3);
    if(x() <= 0+_radius || x() >= 900-_radius){
        _directionX = -_directionX;
    }
    if(y() <= 0+_radius || y() >= 600-_radius){
        _directionY = -_directionY;
    }

}

int Objekat::getRadius()
{
    return _radius;
}

void Objekat::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Right:
            moveBy(10, 10);
            break;
    }

    update();
}

int Objekat::getDirectionX()
{
    return _directionX;
}

int Objekat::getDirectionY()
{
    return _directionY;
}

void Objekat::setDirectionX(int x)
{
    _directionX = x;
}

void Objekat::setDirectionY(int y)
{
    _directionY = y;
}
