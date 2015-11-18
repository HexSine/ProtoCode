#ifndef CHARACTER_H
#define CHARACTER_H

#include "ProtoEngine\ProtoEngine.h"
#include "Input/inputkeys.h"
class Character : public Entity
{
    public:
        Character();
        virtual ~Character();

        virtual void Init();
        virtual void Update(float deltaTime,UpdateContext& context);
        virtual void Terminate();


        InputKeys input;
        u32 m_PlayerID;
        glm::vec3 m_Forward;
        BoxCollider m_Collider;
    protected:
        virtual void SetStats() = 0;
        virtual void SetControls();


        bool m_isLatched;
        float m_Grav;
        float m_RunSpeed;
        float m_JumpSpeed;
        glm::vec3 m_Vel;
    private:
};

#endif // CHARACTER_H
