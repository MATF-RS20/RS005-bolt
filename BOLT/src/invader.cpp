#include <iostream>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include "headers/invader.h"
#include "headers/projectile.h"
#include <QGraphicsScene>
invader::invader()
{

}


QRectF invader::boundingRect() const
{
    return QRectF(-25, -25,50,50);
}

QPainterPath invader::shape() const
{
    QPainterPath path;
    path.addRect(-25, -25,50,50);
    return path;
}
void invader::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    QColor r(100,0,50);
    painter->setBrush(r);
    painter->drawRect(-25, -25,50,50);
}



void invader::advance(int step)
{

    if (!step){
        if(x()<850 && _sgn==1){
            setPos(x()+2,y());
        }else if(x()>=850){
            setPos(x()-2,y()+50);
            _sgn=0;

        }else if(x()>0 && _sgn==0){
            setPos(x()-2,y());
        }else if(_sgn==0 && x()<=0){
            setPos(x()+2,y()+50);
            _sgn=1;
        }
       if(qrand()%1000<1){
            Projectile* p=new Projectile(false,-7);
            p->setPos(x(),y());
            scene()->addItem(p);
        }
       return;
    }



}
