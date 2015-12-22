#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H


class PlayerController : public Entity
{
    public:
        PlayerController(Entity& child, IBatInput& inputSystem);
        virtual ~PlayerController();
        virtual void Update(f32 deltaTime);
    protected:
        Entity& m_Child;
        IBatInput& m_InputSystem;
    private:
};

#endif // PLAYERCONTROLLER_H
