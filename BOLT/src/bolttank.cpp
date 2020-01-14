#include "headers/bolttank.hpp"
#include "headers/projectile.h"
#include <QGraphicsScene>

BoltTank::BoltTank()
{

}
void BoltTank::fire(){
    Projectile* t=new Projectile();
    t->setPos(300,300);
}
