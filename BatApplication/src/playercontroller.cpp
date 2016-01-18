#include "BatApplication/precompiled.h"
#include "BatApplication/Player/playercontroller.h"

PlayerController::PlayerController(Entity& entity) : System(type_id<PlayerController>(),entity)//, m_InputSystem(inputSystem)
{

}
PlayerController::~PlayerController()
{
    //dtor
}
void PlayerController::Update(f32 deltaTime)
{
    /*if(m_InputSystem.GetButton(GLFW_KEY_W))
    {

    }
    if(m_InputSystem.GetButton(GLFW_KEY_S))
    {

    }
    if(m_InputSystem.GetButton(GLFW_KEY_A))
    {
        m_Child.m_Transform.Translate(-100 * deltaTime,0,0);
    }
    if(m_InputSystem.GetButton(GLFW_KEY_D))
    {
        m_Child.m_Transform.Translate(100 * deltaTime,0,0);
    }*/
}
