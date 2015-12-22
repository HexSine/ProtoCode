#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/graphicssystem.h"

#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/GraphicsSystem.h"
#include "ProtoGraphicsLib/renderobject.h"
#include "ProtoGraphicsLib/mesh.h"
#include "ProtoGraphicsLib/material.h"
GraphicsSystem::GraphicsSystem()
{
    //ctor
}

GraphicsSystem::~GraphicsSystem()
{
    //dtor
}
bool GraphicsSystem::Initialize()
{
    return true;
}
void GraphicsSystem::DrawRenderObject(const IBatComponent& target, glm::mat4 MVP)
{
    RenderObject& renObj = (RenderObject&)target;
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, renObj.p_Mesh->m_vertexID);

    glBindTexture(GL_TEXTURE_2D, renObj.p_Material->m_TextureID);

    //glTexImage2D(GL_TEXTURE_2D,0,GL_RG,32,16,0,GL_BGR,GL_UNSIGNED_BYTE,

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(3 * sizeof(f32)));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)(6 * sizeof(f32)));



    GLuint matrixID = glGetUniformLocation(renObj.p_Material->m_ProgramID, "MVP");
    GLuint TileID = glGetUniformLocation(renObj.p_Material->m_ProgramID, "Tile");
    GLuint OffsetID = glGetUniformLocation(renObj.p_Material->m_ProgramID, "Offset");
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

