#include "BatApplication/precompiled.h"
#include "BatApplication/gameplay.h"
Gameplay::Gameplay(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,GameContext& gc) : BaseState(graphicsSystem,inputSystem,gc), m_Controller(m_Bat,m_InputSystem), m_CameraController(m_Bat.m_Transform,m_cam.m_Transform,glm::vec3(0,0,10))
{
    //ctor
}

Gameplay::~Gameplay()
{
    //dtor
}

void Gameplay::Load()
{
    m_InputSystem.SetInputState(&m_InputState);
    std::string URImesh = meshManager.Load("Data/Models/quad.obj");
    std::string URIshader = shaderManager.Load("Data/Shaders/TexturedProgram.glsl");
    std::string URItextureBg = textureManager.Load("Data/Textures/Map/BackGround.png");
    std::string URItextureMap = textureManager.Load("Data/Textures/Map/tileset_brick.png");
    std::string URItextureBat = textureManager.Load("Data/Textures/Characters/Batte.png");
    std::string URImap = m_MapManager.Load("Data/Maps/TestMap.json");

    m_BGMaterial.m_ProgramID = shaderManager.Get(URIshader).m_ProgramID;
    m_BGMaterial.m_TextureID = textureManager.Get(URItextureBg).m_TextureID;

    m_MapMaterial.m_ProgramID = shaderManager.Get(URIshader).m_ProgramID;
    m_MapMaterial.m_TextureID = textureManager.Get(URItextureMap).m_TextureID;

    m_Bat.m_RenderObject.p_Material = &m_BatMaterial;
    m_Bat.m_RenderObject.p_Mesh = meshManager.GetPtr(URImesh);

    m_BatMaterial.m_ProgramID = shaderManager.Get(URIshader).m_ProgramID;
    m_BatMaterial.m_TextureID = textureManager.Get(URItextureBat).m_TextureID;

    m_background.p_Mesh = meshManager.GetPtr(URImesh);
    m_background.p_Material = &m_BGMaterial;



    m_cam.SetView(glm::vec3(256,-128,10),glm::vec3(256,-128,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);

    p_Map = m_MapManager.GetPtr(URImap);
    u32 c = p_Map->m_Layers.size();
    for(u32 i = 0; i < c; ++i)
    {
        p_Map->m_Layers[i].m_Renderable.p_Material = &m_MapMaterial;
    }

    m_Bat.m_Transform.Translate(0,-128,1);

    glUseProgram( m_BGMaterial.m_ProgramID);

    m_InputState.AddKey(GLFW_KEY_W);
    m_InputState.AddKey(GLFW_KEY_S);
    m_InputState.AddKey(GLFW_KEY_A);
    m_InputState.AddKey(GLFW_KEY_D);

    m_InputState.AddKey(GLFW_KEY_UP);
    m_InputState.AddKey(GLFW_KEY_DOWN);
    m_InputState.AddKey(GLFW_KEY_LEFT);
    m_InputState.AddKey(GLFW_KEY_RIGHT);
}

void Gameplay::Unload()
{
    meshManager.UnloadAll();
    shaderManager.UnloadAll();
    textureManager.UnloadAll();
}
int Gameplay::Update(float deltaTime)
{
    int ret = 0;
    m_CameraController.Update();
    m_Controller.Update(deltaTime);
    if(m_InputSystem.GetButton(GLFW_KEY_RIGHT))
    {
        m_cam.m_Transform.Translate(100 * deltaTime,0,0);
    }
    if(m_InputSystem.GetButton(GLFW_KEY_LEFT))
    {
        m_cam.m_Transform.Translate(-100 * deltaTime,0,0);
    }
    if(m_InputSystem.GetButton(GLFW_KEY_UP))
    {
        m_cam.m_Transform.Translate(0,100 * deltaTime,0);
    }
    if(m_InputSystem.GetButton(GLFW_KEY_DOWN))
    {
        m_cam.m_Transform.Translate(0,-100 * deltaTime,0);
    }
    return ret;
}
void Gameplay::Render()
{
    //Draw The Backgroundb
    m_GraphicsSystem.DrawRenderObject(m_background,m_mStack.GetMatrix());

    //m_GraphicsSystem.DrawRenderObject(p_Map->m_Renderable,m_mStack.GetMatrix());

    m_mStack.PushMatrix(m_cam.m_Projection);
    m_mStack.PushMatrix(m_cam.m_Transform.m_transform);

    u32 c = p_Map->m_Layers.size();
    for(u32 i = 0; i < c; ++i)
    {
         m_GraphicsSystem.DrawRenderObject(p_Map->m_Layers[i].m_Renderable,m_mStack.GetMatrix());
    }


    m_mStack.PushMatrix(m_Bat.m_Transform.m_transform);
    m_mStack.PushMatrix(glm::scale(glm::mat4(1),glm::vec3(16,16,1)));

    m_GraphicsSystem.DrawRenderObject(m_Bat.m_RenderObject,m_mStack.GetMatrix());

    m_mStack.Clear();
}
