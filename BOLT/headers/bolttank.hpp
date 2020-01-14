#ifndef BOLTTANK_HPP
#define BOLTTANK_HPP

#include "tank.h"

class BoltTank: public Tank
{
public:
    BoltTank();

    void fire() override;

};

#endif // BOLTTANK_HPP
