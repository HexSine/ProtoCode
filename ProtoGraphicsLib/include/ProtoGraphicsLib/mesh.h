#ifndef MESH_H
#define MESH_H


#include "BatKernel/Resource/resource.h"
struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 UV;
};
class Mesh : public Resource
{
    public:
        Mesh(std::string path);
        Mesh(std::vector<Vertex>& vertices);

        virtual ~Mesh();

        //void InitVertBuffer();
        //void UpdateVertBuffer();
        std::vector<Vertex> m_vertices;

        u32 m_vertexID;
        u32 m_VertCount;

    protected:
        void GenerateBuffer();
        void DestroyBuffer();
        bool isGenerated;
    private:
};

#endif // MESH_H
