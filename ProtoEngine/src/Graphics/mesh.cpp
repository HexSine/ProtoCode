#include "precompiled.h"
#include "mesh.h"

Mesh::Mesh() : p_Vertices(NULL), m_VertCount(0)
{
    //ctor
}

Mesh::Mesh(int Size) : p_Vertices(new Vertex[Size]), m_VertCount(Size)
{

}

Mesh::~Mesh()
{
    SafeDeleteArray(p_Vertices);

    //dtor
}
