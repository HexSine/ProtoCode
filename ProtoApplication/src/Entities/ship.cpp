#include "ship.h"
#include "ProtoEngine\Input\input.h"
#include "ProtoEngine/Graphics/quad.h"
#include "ProtoEngine/Graphics/material.h"
Ship::Ship()
{
    //ctor
}

Ship::~Ship()
{
    //dtor
}
void Ship::Init()
{
    m_Renderable.p_Mesh = new Quad(32,16);
    m_Renderable.Init();
}
void Ship::Update(const double deltaTime)
{
    if(Input::GetKeyDown(GLFW_KEY_D))
    {
        m_Velocity += (glm::vec3(100,0,0) * (float)deltaTime);
    }
    if(Input::GetKeyDown(GLFW_KEY_A))
    {
        m_Velocity += (glm::vec3(-100,0,0) * (float)deltaTime);
    }
    if(Input::GetKeyDown(GLFW_KEY_SPACE))
    {
        m_Velocity.y = 100;
    }
    m_Velocity += glm::vec3(0,-1,0) * 98.0f * (float)deltaTime;
    m_Transform.Translate(m_Velocity * (float)deltaTime);
}
void Ship::Terminate()
{
}
