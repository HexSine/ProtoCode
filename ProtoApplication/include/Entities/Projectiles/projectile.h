#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "ProtoEngine\ProtoEngine.h"
class Projectile : public Entity
{
    public:
        Projectile();
        virtual ~Projectile();
        virtual void Init();
        virtual void Update(f32 deltaTime);
        f32 m_Speed;
        glm::vec3 m_Direction;
    protected:
    private:
};

#endif // PROJECTILE_H
