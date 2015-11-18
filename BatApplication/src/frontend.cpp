#include "BatApplication/precompiled.h"
#include "BatApplication/frontend.h"
FrontEnd::FrontEnd(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,GameContext& gc) : BaseState(graphicsSystem,inputSystem,gc)
{
    //ctor
}

FrontEnd::~FrontEnd()
{
    //dtor
}

void FrontEnd::Load()
{
    std::string URImesh = meshManager.Load("Data/Models/quad.obj");
    std::string URIshader = shaderManager.Load("Data/Shaders/TexturedProgram.glsl");
    std::string URItexture = textureManager.Load("Data/Textures/FrontEnd/BackGround.png");

    std::string URICursorTex = textureManager.Load("Data/Textures/FrontEnd/Batui.png");

    m_CursorMaterial.m_ProgramID = shaderManager.Get(URIshader).m_ProgramID;
    m_CursorMaterial.m_TextureID = textureManager.Get(URICursorTex).m_TextureID;

    m_BGMaterial.m_ProgramID = shaderManager.Get(URIshader).m_ProgramID;
    m_BGMaterial.m_TextureID = textureManager.Get(URItexture).m_TextureID;

    m_background.p_Mesh = meshManager.GetPtr(URImesh);
    m_background.p_Material = &m_BGMaterial;

    m_cursor.p_Mesh = meshManager.GetPtr(URImesh);
    m_cursor.p_Material = &m_CursorMaterial;

    m_CursorPositions[0] = glm::vec3(-64,32,0);
    m_CursorPositions[1] = glm::vec3(-64,-32,0);

    m_Cursor.m_Transform.SetPosition(m_CursorPositions[0]);

    m_cam.SetView(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);

    glUseProgram( m_BGMaterial.m_ProgramID);
}
void FrontEnd::Unload()
{
    meshManager.UnloadAll();
    shaderManager.UnloadAll();
    textureManager.UnloadAll();
}
int FrontEnd::Update(float deltaTime)
{
    if(m_InputSystem.GetKeyDown(GLFW_KEY_S))
    {
        m_Cursor.m_Transform.SetPosition(m_CursorPositions[1]);
    }
    else if(m_InputSystem.GetKeyDown(GLFW_KEY_W))
    {
        m_Cursor.m_Transform.SetPosition(m_CursorPositions[0]);
    }
    return 0;
}
void FrontEnd::Render()
{
    //Draw The Backgroundb
    m_GraphicsSystem.DrawRenderObject(m_background,m_mStack.GetMatrix());

    m_mStack.PushMatrix(m_cam.m_Projection);
    m_mStack.PushMatrix(m_cam.m_View);

    glm::mat4 scaleMat(16.0f);
    scaleMat[3][3] = 1;
    m_mStack.PushMatrix(m_Cursor.m_Transform.m_transform * scaleMat);

    m_GraphicsSystem.DrawRenderObject(m_cursor,m_mStack.GetMatrix());

    m_mStack.Clear();
}
