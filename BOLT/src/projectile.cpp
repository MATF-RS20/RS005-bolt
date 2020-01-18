#include "headers/projectile.h"
#include "headers/invader.h"
#include <QPainter>
#include <QGraphicsScene>
Projectile::Projectile(bool isTank,int speed)
    :_isTenk(isTank),_speed(speed)
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

    QColor r(qrand()%256,qrand()%256,qrand()%256);
    painter->setBrush(r);
    painter->drawEllipse(-4,-5,8,10);
}



void Projectile::advance(int step)
{
    if (!step)
    {
         auto list = this->scene()->collidingItems(this);
         foreach (QGraphicsItem* i, list) {
              invader* item=dynamic_cast<invader*>(i);
              if(item){
                    if(!_isTenk){
                 }
               else{
                 delete list[0];
                 delete this;
                }
              }
            }
         return;
     }else{
        if(y()>10){
      //     auto a=y();
               setPos(x(),y()-_speed);
         }
        else{
            delete this;
        }

    }

}
