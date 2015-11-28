#include "tile_box.h"

tile_box::tile_box() : Entity(&m_Collider)
{
    //ctor
}

tile_box::~tile_box()
{
    //dtor
}
void tile_box::Init()
{
    m_Renderable.p_Mesh = new Quad(32.0f,32.0f);
    m_Renderable.Init();
    m_Collider.m_Size = glm::vec2(32.0f,32.0f);
}
