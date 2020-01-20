#include <iostream>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include "headers/invader.h"
#include "headers/projectile.h"
#include <QGraphicsScene>
invader::invader(int sgn,int speedLevel,int bingo)
    :_sgn(sgn),_speedLevel(speedLevel),_bingo(bingo)
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

    painter->drawPixmap(-25, -25, 50, 50, QPixmap(":/images/in.png"));
//    QColor r(100,0,50);
//    painter->setBrush(r);
//    painter->drawRect(-25, -25,50,50);
}



void invader::advance(int step)
{

    if (!step){
        if(x()<850 && _sgn==1){
            setPos(x()+_speedLevel,y());
        }else if(x()>=850){
            setPos(x()-_speedLevel,y()+50);
            _sgn=0;

        }else if(x()>0 && _sgn==0){
            setPos(x()-_speedLevel,y());
        }else if(_sgn==0 && x()<=50){
            setPos(x()+_speedLevel,y()+50);
            _sgn=1;
        }
       if(qrand()%10000<_bingo){
            Projectile* p=new Projectile(false,-3);
            p->setPos(x(),y());
            scene()->addItem(p);
        }
       if(_toBeDeleted)
           delete this;
       return;
    }

}

void invader::toBeDeleted(){
    _toBeDeleted = true;
}

