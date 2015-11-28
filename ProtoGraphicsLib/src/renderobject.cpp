#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/mesh.h"
#include "ProtoGraphicsLib/renderobject.h"

RenderObject::RenderObject() : p_Mesh(NULL), p_Material(NULL),m_Offset(0,0),m_Tile(1,1), m_Frame(0)
{
}

RenderObject::~RenderObject()
{
}

void RenderObject::Init()
{
}
