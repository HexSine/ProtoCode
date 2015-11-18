#include "projectile.h"

Projectile::Projectile()
{
    //ctor
}

Projectile::~Projectile()
{
    //dtor
}
void Projectile::Init()
{
    m_Renderable.p_Mesh = new Quad(32.0f,16.0f);
    m_Renderable.Init();
}
void Projectile::Update(f32 deltaTime)
{
    //m_Transform.Translate(glm::vec3(0,0,0));
    m_Transform.Translate(m_Direction * m_Speed * deltaTime);
}
