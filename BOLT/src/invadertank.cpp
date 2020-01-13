#include "headers/invadertank.h"
#include "headers/projectile.h"
#include <QGraphicsScene>
InvaderTank::InvaderTank()
{
}

void InvaderTank::fire(){
    Projectile* t=new Projectile();
    t->setPos(x(),y()-37.5);
    this->scene()->addItem(t);
}