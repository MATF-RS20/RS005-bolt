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
    return QRectF(-10,-9,10,9);
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addRect(-10,-9,10,9);
    return path;
}
void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    QColor r(qrand()%256,qrand()%256,qrand()%256);
    painter->setBrush(r);
    painter->drawEllipse(-10,-9,10,9);
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
                 item->toBeDeleted();
                 delete this;
                }
              }
            }
         return;
     }else{
        setPos(x(),y()-_speed);
        if(y()<=20){
            if(_isTenk)
             delete this;
        }
        if(y()>=560){
            if(!_isTenk)
                 delete this;
        }
    }

}
