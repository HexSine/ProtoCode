#include "ProtoEngine/precompiled.h"
#include "ProtoEngine/Graphics/render_object.h"
#include "ProtoEngine/Graphics/mesh.h"
#include "ProtoEngine/Graphics/material.h"
#include "ProtoEngine/Graphics/camera.h"

RenderObject::RenderObject() : p_Mesh(NULL), p_Material(NULL),m_Offset(0,0),m_Tile(1,1), m_Frame(0)
{
    //ctor
}

RenderObject::~RenderObject()
{
    SafeDelete(p_Mesh);
    //dtor
}

void RenderObject::Init()
{
    glGenVertexArrays(1,&p_Mesh->m_vertexID);
    glBindVertexArray(p_Mesh->m_vertexID);

    glGenBuffers(1, &p_Mesh->m_vertexID);
    glBindBuffer(GL_ARRAY_BUFFER, p_Mesh->m_vertexID);
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * p_Mesh->m_VertCount,&p_Mesh->p_Vertices[0],GL_STATIC_DRAW);
}
