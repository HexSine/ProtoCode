#ifndef ARCHER_H
#define ARCHER_H

#include "Entities\Characters\character.h"
#include "Entities\Projectiles\projectile.h"
class Archer : public Character
{
    public:
        Archer();
        virtual ~Archer();

    protected:
        virtual void SetStats();
    private:
};

#endif // ARCHER_H
