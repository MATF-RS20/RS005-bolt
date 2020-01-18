#include "headers/invadertank.h"
#include "headers/projectile.h"
#include <QGraphicsScene>

InvaderTank::InvaderTank()
{
}

void InvaderTank::fire(){
        Projectile* t=new Projectile(true);
        t->setPos(x(),y()-55.5);
        this->scene()->addItem(t);
}

void InvaderTank::advance(int step)
{

    if (!step) {
        auto list = this->scene()->collidingItems(this);
        if(!list.isEmpty()){
          //  delete list[0];
            delete this;
        }
        return;
    }


}
