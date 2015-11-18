#include "ProtoEngine/precompiled.h"
#include "ProtoEngine/GraphicsSystem.h"
#include "ProtoEngine/matrixstack.h"
#include "ProtoEngine/Graphics/render_object.h"
#include "ProtoEngine/Graphics/mesh.h"
#include "ProtoEngine/Graphics/material.h"
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
}
void GraphicsSystem::DrawRenderObject(const RenderObject& target, glm::mat4 MVP)
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, target.p_Mesh->m_vertexID);

    glBindTexture(GL_TEXTURE_2D, target.p_Material->m_TextureID);

    //glTexImage2D(GL_TEXTURE_2D,0,GL_RG,32,16,0,GL_BGR,GL_UNSIGNED_BYTE,

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(3 * sizeof(f32)));
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(7 * sizeof(f32)));



    GLuint matrixID = glGetUniformLocation(target.p_Material->m_ProgramID, "MVP");
    GLuint TileID = glGetUniformLocation(target.p_Material->m_ProgramID, "Tile");
    GLuint OffsetID = glGetUniformLocation(target.p_Material->m_ProgramID, "Offset");
    glUniformMatrix4fv(matrixID,1,GL_FALSE, &MVP[0][0]);
    glUniform2fv(TileID,1,&target.m_Tile[0]);

    glm::vec2 tileOfffset = target.m_Offset;
    tileOfffset.x = tileOfffset.x + target.m_Tile.x * target.m_Frame.x;
    tileOfffset.y = tileOfffset.y + target.m_Tile.y * target.m_Frame.y;
    glUniform2fv(OffsetID,1,&tileOfffset[0]);

    glDrawArrays(GL_TRIANGLES,0,6);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}
void GraphicsSystem::SetTexture(u32 TextureID)
{
}
void GraphicsSystem::SetProgram(u32 ProgramID)
{
    glUseProgram(ProgramID);
}
void GraphicsSystem::SetVertexBuffer(u32 VertexBufferID)
{
}
void GraphicsSystem::SetIndexBuffer(u32 IndexBufferID)
{
}
u32 GraphicsSystem::LoadProgram(const char* vertex_file_path, const char* fragment_file_path)
{
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}
