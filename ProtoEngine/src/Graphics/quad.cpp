#include "quad.h"

Quad::Quad(float width, float height) : Mesh(6)
{
    Initialize(width,height,glm::vec3(0,0,0),1,1);
}
Quad::Quad(float width, float height,glm::vec3 pivot) : Mesh(6)
{
    Initialize(width,height,pivot,1,1);
}
Quad::Quad(float width, float height, float u, float v) : Mesh(6)
{
    Initialize(width,height,glm::vec3(0,0,0),u,v);
}
Quad::Quad(float width, float height,glm::vec3 pivot, float u, float v) : Mesh(6)
{
    Initialize(width,height,pivot,u,v);
}

Quad::~Quad()
{

    //dtor
}
void Quad::Initialize(float width, float height,glm::vec3 pivot, float u, float v)
{

//Set Positions based on width and height
    p_Vertices[0].Position = glm::vec3(-width * 0.5f, height * 0.5f, 0) + pivot;
    p_Vertices[1].Position = glm::vec3(width * 0.5f, height * 0.5f, 0) + pivot;
    p_Vertices[2].Position = glm::vec3(-width * 0.5f, -height * 0.5f, 0) + pivot;
    p_Vertices[3].Position = glm::vec3(width * 0.5f, height * 0.5f, 0) + pivot;
    p_Vertices[4].Position = glm::vec3(width * 0.5f, -height * 0.5f, 0) + pivot;
    p_Vertices[5].Position = glm::vec3(-width * 0.5f, -height * 0.5f, 0) + pivot;

//Set default color of each Vertex to 1
    p_Vertices[0].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    p_Vertices[1].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    p_Vertices[2].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    p_Vertices[3].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    p_Vertices[4].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    p_Vertices[5].Color = glm::vec4(1.0f,1.0f,1.0f,1.0f);

//Set default UVs
    p_Vertices[0].UV = glm::vec2(0.0f,v);
    p_Vertices[1].UV = glm::vec2(u,v);
    p_Vertices[2].UV = glm::vec2(0.0f,0.0f);
    p_Vertices[3].UV = glm::vec2(u,v);
    p_Vertices[4].UV = glm::vec2(u,0.0f);
    p_Vertices[5].UV = glm::vec2(0.0f,0.0f);
}

