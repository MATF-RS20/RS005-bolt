#include "headers/objekat.hpp"
#include "headers/boltprojectile.hpp"
#include "headers/bolttank.hpp"

#include <QDebug>
#include <QList>

Objekat::Objekat(int radius)
    : _radius(radius),
      _directionX(5), _directionY(5)
{
    setPos(450,100);
    setZValue(1);
}

Objekat::~Objekat()
{
}

void Objekat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(_radius>10){
        painter->setBrush(Qt::red);
        QList<QGraphicsItem*> collidedItems = collidingItems(Qt::IntersectsItemShape);

        if (!collidedItems.isEmpty()) {
            //delete this;
            QGraphicsItem* item = collidedItems.first();
            BoltTank *tank = dynamic_cast<BoltTank*>(item);
            BoltProjectile *projectile = dynamic_cast<BoltProjectile*>(item);

            if (projectile) {       // Sudar sa projektilom
                //qDebug() << "SALJEM SIGNAL";

                // Projektil se sudario sa loptom, potrebno je poslati signal u Igrica1 da se obrise stara lopta i napravi nove
                // Signalu treba proslediti koordinate lopte koji je unisten, da bi se lopte napravile iz te pozicije
//                emit loptaPogodjena();
                //qDebug() << "SIGNAL PRIMLJEN";
//                delete this;

            }
            else if (tank) {        // Sudar sa tenkom
                tank->setLife(tank->getLife()-1);
                if (tank->getLife() <= 0) {     // Kraj igre
                    // TODO: posalji signal Igrici1 da se igra zavrsila i pozovi GameOver
                }
            } else {
                // Lopte se medjusobno sudaraju - IGNORISATI
            }
        }
        painter->drawEllipse(QPoint(0, 0), _radius, _radius);
    }
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

int Objekat::getX()
{
    return static_cast<int>(x());
}

int Objekat::getY()
{
    return static_cast<int>(y());
}

