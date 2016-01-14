#include "BatApplication/precompiled.h"
#include "BatApplication/gameplay.h"


Gameplay::Gameplay(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc)
    : BaseState(graphicsSystem,inputSystem,resSystem,gc), m_Controller(m_Bat,m_InputSystem), m_CameraController(m_Bat.m_Transform,m_cam.m_Transform,glm::vec3(0,0,10)),mEntFactory(resSystem)
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
    std::string URImesh = m_ResourceData.Load<Mesh>("Data/Models/quad.obj");
    std::string URIshader = m_ResourceData.Load<Shader>("Data/Shaders/TexturedProgram.glsl");
    std::string URItextureBg = m_ResourceData.Load<Texture>("Data/Textures/Map/BackGround.png");
    std::string URItextureMap = m_ResourceData.Load<Texture>("Data/Textures/Map/tileset_brick.png");
    std::string URItextureBat = m_ResourceData.Load<Texture>("Data/Textures/Characters/Batte.png");
    std::string URImap = m_ResourceData.Load<Map>("Data/Maps/TestMap.json");

    std::string URIBackgroundMat = m_ResourceData.Load<Material>("Data/Materials/Gameplay/BackgroundMat.mat");
    std::string URIMapMat = m_ResourceData.Load<Material>("Data/Materials/Gameplay/MapMat.mat");
    std::string URIBatMat = m_ResourceData.Load<Material>("Data/Materials/Gameplay/BatMat.mat");

    m_Bat.m_RenderObject.p_Material = m_ResourceData.GetPtr<Material>(URIBatMat);
    m_Bat.m_RenderObject.p_Mesh = m_ResourceData.GetPtr<Mesh>(URImesh);

    m_background.p_Mesh = m_ResourceData.GetPtr<Mesh>(URImesh);
    m_background.p_Material = m_ResourceData.GetPtr<Material>(URIBackgroundMat);



    m_cam.SetView(glm::vec3(256,-128,10),glm::vec3(256,-128,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);

    p_Map = m_ResourceData.GetPtr<Map>(URImap);
    u32 c = p_Map->m_Layers.size();

    for(u32 i = 0; i < c; ++i)
    {
        SpawnLayer(p_Map->m_Layers[i]);
    }

    m_Bat.m_Transform.Translate(0,-128,1);

    glUseProgram(m_ResourceData.Get<Shader>(URIshader).m_ProgramID);

    m_InputState.AddKey(GLFW_KEY_W);
    m_InputState.AddKey(GLFW_KEY_S);
    m_InputState.AddKey(GLFW_KEY_A);
    m_InputState.AddKey(GLFW_KEY_D);

    m_InputState.AddKey(GLFW_KEY_UP);
    m_InputState.AddKey(GLFW_KEY_DOWN);
    m_InputState.AddKey(GLFW_KEY_LEFT);
    m_InputState.AddKey(GLFW_KEY_RIGHT);
}
void Gameplay::SpawnLayer(Layer& layer)
{
    u32& lType = layer.m_Type;
    if(lType < 2)
    {
        RenderObject* renObj = new RenderObject;

        renObj->Init();
        //renObj->m_Tile = glm::vec2(t,t);
        //renObj->m_Offset = glm::vec2(0.0f,224.0f/256.0f);
        renObj->p_Material = m_ResourceData.GetPtr<Material>("Data/Materials/Gameplay/MapMat.mat");
        p_Map->GenerateLayerMesh(layer,*renObj);
        m_Renderables.push_back(renObj);
    }
    else
    {
        std::vector<u32> ids;
        p_Map->GetObjectIDs(layer,ids);
        u32 index = 0;
        for(s32 y = 0; y < p_Map->m_Height; ++y)
        {
            for(s32 x = 0; x < p_Map->m_Width; ++x)
            {
                mEntFactory.CreateEntity(ids[index],glm::vec3(x * (s32)p_Map->m_tWidth+16,-y * (s32)p_Map->m_tHeight-16,1));
                ++index;
            }
        }
    }
}
void Gameplay::Unload()
{
    m_ResourceData.UnloadAll();
}
int Gameplay::Update(float deltaTime)
{
    int ret = 0;
    m_CameraController.Update();
    m_Controller.Update(deltaTime);
    return ret;
}
void Gameplay::Render()
{
    //Draw The Backgroundb
    m_GraphicsSystem.DrawRenderObject(m_background,m_mStack.GetMatrix());

    //m_GraphicsSystem.DrawRenderObject(p_Map->m_Renderable,m_mStack.GetMatrix());

    m_mStack.PushMatrix(m_cam.m_Projection);
    m_mStack.PushMatrix(m_cam.m_Transform.m_transform);

    u32 c = m_Renderables.size();
    for(u32 i = 0; i < c; ++i)
    {
         m_GraphicsSystem.DrawRenderObject(*m_Renderables[i],m_mStack.GetMatrix());
    }

    std::vector<RenderedEntity*>& entities = mEntFactory.m_Entities;
    c = entities.size();
    for(u32 i = 0; i < c; ++i)
    {
        RenderedEntity*& ent = entities[i];

        m_mStack.PushMatrix(ent->m_Transform.m_transform);
        m_mStack.PushMatrix(glm::scale(glm::mat4(1),glm::vec3(16,16,1)));
        m_GraphicsSystem.DrawRenderObject(ent->m_RenderObject,m_mStack.GetMatrix());
        m_mStack.PopMatrix();
        m_mStack.PopMatrix();
    }

    //m_mStack.PushMatrix(m_Bat.m_Transform.m_transform);
    //m_mStack.PushMatrix(glm::scale(glm::mat4(1),glm::vec3(16,16,1)));

    //m_GraphicsSystem.DrawRenderObject(m_Bat.m_RenderObject,m_mStack.GetMatrix());

    m_mStack.Clear();
}

void Gameplay::CreateMapObjects(std::vector<u32>& ids)
{
    for(u32 i = 0, c = ids.size(); i < c; ++i)
    {
        mEntFactory.CreateEntity(ids[i]);
    }
}
