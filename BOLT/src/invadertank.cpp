#include "headers/invadertank.h"
#include "headers/projectile.h"
#include <QGraphicsScene>
#include "headers/tank.h"
#include <QWidget>
#include <QMediaPlayer>

InvaderTank::InvaderTank()
{
    music->setMedia(QUrl("qrc:/music/Laser-shot.mp3"));
}

void InvaderTank::fire(){
        Projectile* t=new Projectile(true);
        t->setPos(x(),y()-55.5);
        this->scene()->addItem(t);

        music->play();
}

void InvaderTank::advance(int step)
{

    if (!step) {
        auto list = this->scene()->collidingItems(this);
        if(!list.isEmpty()){
            delete this;
        }
        return;
    }

    if(!this->hasFocus()){
       this->setFocus();
    }


}
