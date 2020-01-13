#ifndef INVADERTANK_H
#define INVADERTANK_H

#include "tank.h"

class InvaderTank:public Tank
{
public:
    InvaderTank();

    void fire() override;
};

#endif // INVADERTANK_H
