#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/graphicssystem.h"

#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/GraphicsSystem.h"
#include "ProtoGraphicsLib/renderobject.h"
#include "ProtoGraphicsLib/mesh.h"
#include "ProtoGraphicsLib/material.h"
#include "ProtoGraphicsLib/texture.h"
#include "ProtoGraphicsLib/shader.h"
#include "ProtoGraphicsLib/Systems/rendersystem.h"
GraphicsSystem::GraphicsSystem()
{
    //TODO Remove
    id = type_id<Texture>();
    //ctor
}

GraphicsSystem::~GraphicsSystem()
{
    //dtor
}
bool GraphicsSystem::Initialize(ResourceManager* resSystem)
{
    m_ResourceData = resSystem;
    return true;
}
void GraphicsSystem::DrawRenderObject(const System& target, glm::mat4 MVP)
{
    RenderSystem& renObj = (RenderSystem&)target;
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    Texture& texture = m_ResourceData->Get<Texture>(renObj.p_Material->m_TextureID);
    Shader& shader = m_ResourceData->Get<Shader>(renObj.p_Material->m_ProgramID);

    glBindBuffer(GL_ARRAY_BUFFER, renObj.p_Mesh->m_vertexID);
    glBindTexture(GL_TEXTURE_2D, texture.m_TextureID);

    //glTexImage2D(GL_TEXTURE_2D,0,GL_RG,32,16,0,GL_BGR,GL_UNSIGNED_BYTE,

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(3 * sizeof(f32)));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(6 * sizeof(f32)));


    GLuint matrixID = glGetUniformLocation(shader.m_ProgramID, "MVP");
    GLuint TileID = glGetUniformLocation(shader.m_ProgramID, "Tile");
    GLuint OffsetID = glGetUniformLocation(shader.m_ProgramID, "Offset");
    glUniformMatrix4fv(matrixID,1,GL_FALSE, &MVP[0][0]);
    glUniform2fv(TileID,1,&renObj.m_Tile[0]);

    glm::vec2 tileOfffset = renObj.m_Offset;
    tileOfffset.x = tileOfffset.x + renObj.m_Tile.x * renObj.m_Frame.x;
    tileOfffset.y = tileOfffset.y + renObj.m_Tile.y * renObj.m_Frame.y;
    glUniform2fv(OffsetID,1,&tileOfffset[0]);

    glDrawArrays(GL_TRIANGLES,0,renObj.p_Mesh->m_VertCount);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

