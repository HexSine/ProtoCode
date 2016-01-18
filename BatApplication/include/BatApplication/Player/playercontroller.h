#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H


class PlayerController : public System
{
    public:
        PlayerController(Entity& entity);
        virtual ~PlayerController();
        virtual void Update(f32 deltaTime);
    protected:
        //IBatInput& m_InputSystem;
    private:
};

#endif // PLAYERCONTROLLER_H
