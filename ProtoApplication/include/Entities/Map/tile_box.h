#ifndef TILE_BOX_H
#define TILE_BOX_H


#include "ProtoEngine\ProtoEngine.h"

class tile_box : public Entity
{
    public:
        tile_box();
        virtual ~tile_box();
        virtual void Init();

        BoxCollider m_Collider;

    protected:
    private:
};

#endif // TILE_BOX_H
