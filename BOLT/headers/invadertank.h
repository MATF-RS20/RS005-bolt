#ifndef INVADERTANK_H
#define INVADERTANK_H

#include "headers/tank.h"
#include <QObject>
#include <QMediaPlayer>
class InvaderTank:public Tank
{
public:
    InvaderTank();
    void fire() override;
    void advance(int step) override;
signals:
    void poraz();
private:
    QMediaPlayer * music = new QMediaPlayer();

};

#endif // INVADERTANK_H
