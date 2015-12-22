#ifndef ENTITY_H
#define ENTITY_H

#include "BatKernel/object.h"
class Entity : public Object
{
    public:
        Entity();
        virtual ~Entity();

        virtual void Init(){};
        virtual void Update(){};
        virtual void Terminate(){};
        virtual void Render(){};

        bool m_Active;
        Transform m_Transform;
    protected:
    private:
};

#endif // ENTITY_H
