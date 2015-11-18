#include "background.h"

Background::Background()
{
    //ctor
}

Background::~Background()
{
    //dtor
}
void Background::Init()
{
    m_Renderable.p_Mesh = new Quad(480.0f,288.0f);
    m_Renderable.Init();
}
