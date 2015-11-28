#include "character.h"

Character::Character() : Entity(&m_Collider)
{
    //ctor
}

Character::~Character()
{
    //dtor
}
void Character::SetControls()
{
    if(m_PlayerID == 1)
    {
        input.UP = GLFW_KEY_W;
        input.DOWN = GLFW_KEY_S;
        input.LEFT = GLFW_KEY_A;
        input.RIGHT = GLFW_KEY_D;
        input.PRIMARY = GLFW_KEY_F;
    }
    else if(m_PlayerID == 2)
    {
        input.UP = GLFW_KEY_UP;
        input.DOWN = GLFW_KEY_DOWN;
        input.LEFT = GLFW_KEY_LEFT;
        input.RIGHT = GLFW_KEY_RIGHT;
        input.PRIMARY = GLFW_KEY_KP_0;
    }
}
void Character::Init()
{
    m_Grav = 400.0f;
    m_Renderable.p_Mesh = new Quad(32.0f,32.0f);
    m_Renderable.Init();
    float t = 32.0f/256.0f;
    m_Renderable.m_Tile = glm::vec2(t,t);
    m_Renderable.m_Offset = glm::vec2(0.0f,224.0f/256.0f);


    m_Collider.m_Size = glm::vec2(32,32);

    m_isLatched = false;
    SetStats();
    SetControls();
}
void Character::Update(float deltaTime,UpdateContext& context)
{
    m_Vel.x = 0;
    if(Input::GetKeyDown(input.RIGHT))
    {
        m_Vel.x = m_RunSpeed;
        m_Renderable.m_Offset.x = 0;
    }
    if(Input::GetKeyDown(input.LEFT))
    {
        m_Vel.x = -m_RunSpeed;
        m_Renderable.m_Offset.x = 32.0f/256.0f;
    }
    if(Input::GetKeyDown(input.PRIMARY))
    {
        m_Vel.y = m_JumpSpeed;
    }
    else if(m_Vel.y > -m_Grav && !m_isLatched)
    {
        m_Vel.y -= 2000.0f * deltaTime;
    }
    else if(!m_isLatched)
    {
        m_Vel.y = -m_Grav;
    }
    PointInfo info;
    if(context.m_CollisionSystem.CheckPoint(m_Transform.GetPosition() - glm::vec3(0,16,0),&info))
    {
        if(info.m_isStatic && m_Vel.y < 0)
        {
            m_Vel.y = 0;
        }
        else if(info.m_Entity != this)
        {
            m_Vel.y = m_JumpSpeed;
        }
    }
    if(context.m_CollisionSystem.CheckPoint(m_Transform.GetPosition() + glm::vec3(0,16,0),&info))
    {
        if(info.m_isStatic )
        {
            if(m_Vel.y > 0)
            {
                m_Vel.y = 0;
            }
            m_isLatched = Input::GetKeyDown(input.UP);
            if(m_isLatched)
            {
                m_Renderable.m_Offset.y = 160.0f/256.0f;
            }
            else
            {
                m_Renderable.m_Offset.y = 224.0f/256.0f;
            }
        }
        else if(m_isLatched)
        {
            m_Renderable.m_Offset.y = 224.0f/256.0f;
            m_isLatched = false;
        }

    }
    else if(m_isLatched)
    {
        m_Renderable.m_Offset.y = 224.0f/256.0f;
        m_isLatched = false;
    }

    m_Forward = glm::vec3(1,0,0);
    m_Transform.Translate(m_Vel * deltaTime);
}
void Character::Terminate()
{
}
