#ifndef ENTITY_H
#define ENTITY_H

#include "transform.h"
#include "Physics/collisionsystem.h"

class BoxCollider;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual void Update(float deltaTime){}
        virtual void Init(){}
        virtual void Terminate(){}

        bool m_Active;
        Transform m_Transform;
    protected:
    private:
};

#endif // ENTITY_H
