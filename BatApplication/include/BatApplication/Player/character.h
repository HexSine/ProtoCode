#ifndef CHARACTER_H
#define CHARACTER_H

#include "BatKernel/entity.h"
#include "ProtoGraphicsLib/renderobject.h"
class Character : public Entity
{
    public:
        Character();
        virtual ~Character();
        RenderObject m_RenderObject;
    protected:
    private:
};

#endif // CHARACTER_H
