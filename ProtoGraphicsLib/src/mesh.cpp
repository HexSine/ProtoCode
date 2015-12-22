#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/mesh.h"

Mesh::Mesh(std::string path) : m_vertexID(0), m_VertCount(0), isGenerated(false)
{

    FILE* file = fopen(path.c_str(), "r");

    if( file == NULL ){
        printf("Hey dogger I don't think the mesh can be opened at path %s\n", path.c_str());
        return;
    }

    char lineHeader[128];
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;

    std::vector<u32> vertexIndices;
    std::vector<u32> uvIndices;
    std::vector<u32> normalIndices;

    while(fscanf(file,"%s127",lineHeader) != EOF)
    {
        if(strcmp(lineHeader,"v") == 0)
        {
            glm::vec3 vertex;
            fscanf(file,"%f %f %f\n", &vertex.x,&vertex.y,&vertex.z);
            vertices.push_back(vertex);
        }
        else if(strcmp(lineHeader,"vt") == 0)
        {
            glm::vec2 uv;
            fscanf(file,"%f %f\n", &uv.x,&uv.y);
            uvs.push_back(uv);
        }
        else if(strcmp(lineHeader,"vn") == 0)
        {
            glm::vec3 normal;
            fscanf(file,"%f %f %f\n", &normal.x,&normal.y,&normal.z);
            normals.push_back(normal);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 ){
            u32 vertexIndex[3], uvIndex[3], normalIndex[3];
            u32 matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }

    for(u32 i = 0,c = vertexIndices.size(); i < c; ++i)
    {
        u32 vertexIndex = vertexIndices[i];
        u32 normalIndex = normalIndices[i];
        u32 uvIndex = uvIndices[i];
        Vertex vertex;
        vertex.Position = vertices[vertexIndex - 1];
        vertex.Normal = normals[normalIndex - 1];
        vertex.UV = uvs[uvIndex - 1];
        m_vertices.push_back(vertex);

    }
    m_VertCount = m_vertices.size();

    glGenVertexArrays(1,&m_vertexID);
    glBindVertexArray(m_vertexID);

    glGenBuffers(1, &m_vertexID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexID);
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * m_vertices.size(),&m_vertices[0],GL_STATIC_DRAW);
}

Mesh::Mesh(std::vector<Vertex>& vertices) : m_vertexID(0), m_VertCount(vertices.size()), isGenerated(false)
{
    m_vertices = vertices;

    GenerateBuffer();

}
Mesh::~Mesh()
{
    if(isGenerated)
    {
        DestroyBuffer();
    }
}
void Mesh::DestroyBuffer()
{
    glDeleteBuffers(1,&m_vertexID);
    glDeleteVertexArrays(1,&m_vertexID);
}

void Mesh::GenerateBuffer()
{
    if(isGenerated)
    {
        DestroyBuffer();
    }
    glGenVertexArrays(1,&m_vertexID);
    glBindVertexArray(m_vertexID);

    glGenBuffers(1, &m_vertexID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexID);
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * m_vertices.size(),&m_vertices[0],GL_STATIC_DRAW);
    isGenerated = true;
}
