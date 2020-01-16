#include "headers/projectile.h"
#include <QPainter>
#include <QGraphicsScene>
Projectile::Projectile()
{

}
QRectF Projectile::boundingRect() const
{
    return QRectF(-3,-4,6,8);
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addRect(-3,-4,6,8);
    return path;
}
void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    QColor r(255,0,0);
    painter->setBrush(r);
    painter->drawRect(-3,-4,6,8);
}



void Projectile::advance(int step)
{

    if (!step)
    {
         auto list = this->scene()->collidingItems(this);
         if(!list.isEmpty()){
             delete list[0];
             delete this;
          }
        return;
    }

    if (y()<600){
       auto a=y();
        setPos(x(),y()-_speed);
    }
    else{

        delete this;
    }
}

