#ifndef SHIP_H
#define SHIP_H


#include "ProtoEngine/ProtoEngine.h"


class Ship : public Entity
{
    public:
        Ship();
        virtual ~Ship();
        virtual void Init();
        virtual void Update(const double deltaTime);
        virtual void Terminate();
    protected:
        glm::vec3 m_Velocity;
    private:
};

#endif // SHIP_H
