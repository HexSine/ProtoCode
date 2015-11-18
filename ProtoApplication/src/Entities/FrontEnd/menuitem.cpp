#include "menuitem.h"

#include "ProtoEngine\Input\input.h"
#include "ProtoEngine/Graphics/quad.h"
#include "ProtoEngine/Graphics/material.h"

MenuItem::MenuItem()
{
    //ctor
}

MenuItem::~MenuItem()
{
    //dtor
}
void MenuItem::Init()
{
    m_Renderable.p_Mesh = new Quad(128,32);
    m_Renderable.Init();
}
void MenuItem::Update(const double deltaTime)
{
}
void MenuItem::Terminate()
{
}
