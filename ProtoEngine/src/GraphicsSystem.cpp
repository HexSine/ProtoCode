#include "../precompiled.h"
#include "ProtoEngine/GraphicsSystem.h"

GraphicsSystem::GraphicsSystem()
{
    //ctor
}

GraphicsSystem::~GraphicsSystem()
{
    //dtor
}
void GraphicsSystem::Initialize()
{
    glewInit();
    glGenVertexArrays(3,&VertexArrayID);
    glBindVertexArray(VertexArrayID);
}

