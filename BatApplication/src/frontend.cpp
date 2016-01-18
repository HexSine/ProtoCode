#include "BatApplication/precompiled.h"
#include "BatApplication/frontend.h"
FrontEnd::FrontEnd(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc) : BaseState(graphicsSystem,inputSystem,resSystem,gc), m_CursorIndex(0)
{
    //ctor
}

FrontEnd::~FrontEnd()
{
    //dtor
}

void FrontEnd::Load()
{
    m_InputSystem.SetInputState(&m_InputState);
    std::string URImesh = m_ResourceData.Load<Mesh>("Data/Models/quad.obj");
    std::string URIshader = m_ResourceData.Load<Shader>("Data/Shaders/TexturedProgram.glsl");
    std::string URItexture = m_ResourceData.Load<Texture>("Data/Textures/FrontEnd/BackGround.png");

    std::string URICursorTex = m_ResourceData.Load<Texture>("Data/Textures/FrontEnd/Batui.png");
    std::string URICursorMaterial = m_ResourceData.Load<Material>("Data/Materials/FrontEnd/CursorMat.mat");
    std::string URIBackgroundMaterial = m_ResourceData.Load<Material>("Data/Materials/FrontEnd/BackgroundMat.mat");

    RenderSystem* bgRenSys = m_background.AddSystem<RenderSystem>();
    bgRenSys->p_Mesh = m_ResourceData.GetPtr<Mesh>(URImesh);
    bgRenSys->p_Material = m_ResourceData.GetPtr<Material>(URIBackgroundMaterial);

    RenderSystem* cursorRenSys = m_Cursor.AddSystem<RenderSystem>();
    cursorRenSys->p_Mesh = m_ResourceData.GetPtr<Mesh>(URImesh);
    cursorRenSys->p_Material = m_ResourceData.GetPtr<Material>(URICursorMaterial);

    m_CursorPositions[0] = glm::vec3(-64,64,0);
    m_CursorPositions[1] = glm::vec3(-64,-64,0);
    m_CursorPositions[2] = glm::vec3(-64,0,0);

    m_Cursor.m_Transform.SetPosition(m_CursorPositions[0]);

    m_cam.SetView(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);

    glUseProgram(m_ResourceData.Get<Shader>(URIshader).m_ProgramID);

    m_InputState.AddKey(GLFW_KEY_UP);
    m_InputState.AddKey(GLFW_KEY_DOWN);
    m_InputState.AddKey(GLFW_KEY_ENTER);

}
void FrontEnd::MoveUp()
{
    m_CursorIndex = (m_CursorIndex+1) % 3;
    m_Cursor.m_Transform.SetPosition(m_CursorPositions[m_CursorIndex]);
}
void FrontEnd::MoveDown()
{
    m_CursorIndex = (m_CursorIndex+2) % 3;
    m_Cursor.m_Transform.SetPosition(m_CursorPositions[m_CursorIndex]);
}
void FrontEnd::Unload()
{
    m_ResourceData.UnloadAll();
}
int FrontEnd::Update(float deltaTime)
{
    int ret = 0;
    if(m_InputSystem.GetButtonDown(GLFW_KEY_UP))
    {
        MoveUp();
    }
    if(m_InputSystem.GetButtonDown(GLFW_KEY_DOWN))
    {
        MoveDown();
    }
    if(m_InputSystem.GetButtonDown(GLFW_KEY_ENTER))
    {
        ret = 2;
    }
    return ret;
}
void FrontEnd::Render()
{
    //Draw The Background
    m_GraphicsSystem.DrawRenderObject(*m_background.GetSystem<RenderSystem>(),m_mStack.GetMatrix());

    m_mStack.PushMatrix(m_cam.m_Projection);
    m_mStack.PushMatrix(m_cam.m_Transform.m_transform);

    glm::mat4 scaleMat(16.0f);
    scaleMat[3][3] = 1;
    m_mStack.PushMatrix(m_Cursor.m_Transform.m_transform * scaleMat);

    m_GraphicsSystem.DrawRenderObject(*m_Cursor.GetSystem<RenderSystem>(),m_mStack.GetMatrix());

    m_mStack.Clear();
}
