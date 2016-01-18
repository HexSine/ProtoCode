#include "ProtoGraphicsLib\Systems\rendersystem.h"

RenderSystem::RenderSystem(Entity& entity) : System(type_id<RenderSystem>(),entity), p_Mesh(NULL), p_Material(NULL),m_Offset(0,0),m_Tile(1,1), m_Frame(0)
{
    //ctor
}

RenderSystem::~RenderSystem()
{
    //dtor
}
