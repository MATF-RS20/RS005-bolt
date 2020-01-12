#include "invadertank.h"
#include "projectile.h"
#include <QGraphicsScene>
InvaderTank::InvaderTank()
{
}

void InvaderTank::fire(){
    projectile* t=new projectile();
    t->setPos(x(),y()-37.5);
    this->scene()->addItem(t);
}
