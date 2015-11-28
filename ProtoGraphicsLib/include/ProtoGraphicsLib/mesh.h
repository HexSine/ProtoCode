#ifndef MESH_H
#define MESH_H


struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 UV;
};
class Mesh
{
    public:
        Mesh(std::string path);

        virtual ~Mesh();

        //void InitVertBuffer();
        //void UpdateVertBuffer();
        std::vector<Vertex> m_vertices;

        u32 m_vertexID;
        u32 m_VertCount;

    protected:
    private:
};

#endif // MESH_H
