#ifndef INVADERTANK_H
#define INVADERTANK_H

#include "headers/tank.h"

class InvaderTank:public Tank
{

public:
    InvaderTank();
    void fire() override;
    void advance(int step) override;
};

#endif // INVADERTANK_H
