#include "BatApplication/precompiled.h"
#include "BatApplication/gameplay.h"


Gameplay::Gameplay(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc)
    : BaseState(graphicsSystem,inputSystem,resSystem,gc), mEntFactory(resSystem)
{
    //ctor
}

Gameplay::~Gameplay()
{
    SafeDeleteVector(m_Renderables);
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

    RenderSystem* bgRenSys = m_background.AddSystem<RenderSystem>();
    bgRenSys->p_Mesh = m_ResourceData.GetPtr<Mesh>(URImesh);
    bgRenSys->p_Material = m_ResourceData.GetPtr<Material>(URIBackgroundMat);





    p_Map = m_ResourceData.GetPtr<Map>(URImap);
    u32 c = p_Map->m_Layers.size();

    for(u32 i = 0; i < c; ++i)
    {
        SpawnLayer(p_Map->m_Layers[i]);
    }

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
        Entity* ent = new Entity();
        RenderSystem* renObj = ent->AddSystem<RenderSystem>();
        renObj->p_Material = m_ResourceData.GetPtr<Material>("Data/Materials/Gameplay/MapMat.mat");
        p_Map->GenerateLayerMesh(layer,*renObj);
        m_Renderables.push_back(ent);
    }
    else
    {
        std::vector<u32> ids;
        p_Map->GetObjectIDs(layer,ids);
        u32 index = 0;
        for(s32 y = 0; y < (s32)p_Map->m_Height; ++y)
        {
            for(s32 x = 0; x < (s32)p_Map->m_Width; ++x)
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
    System::UpdateAllSystems();
    std::vector<System*>& systems = mEntFactory.m_Systems;
    for(u32 i = 0, c = systems.size(); i < c; ++i)
    {
        System* system = systems[i];
        system->Update();
    }
    return ret;
}
void Gameplay::Render()
{
    //Draw The Backgroundb
    m_GraphicsSystem.DrawRenderObject(*m_background.GetSystem<RenderSystem>(),m_mStack.GetMatrix());

    m_mStack.PushMatrix(mEntFactory.m_cam.m_Projection);
    m_mStack.PushMatrix(mEntFactory.m_cam.m_Transform.m_transform);

    u32 c = m_Renderables.size();
    for(u32 i = 0; i < c; ++i)
    {
        RenderSystem* renSys = m_Renderables[i]->GetSystem<RenderSystem>();
        m_GraphicsSystem.DrawRenderObject(*renSys,m_mStack.GetMatrix());
    }

    std::vector<RenderSystem*> renObjects = System::GetSystems<RenderSystem>();// mEntFactory.m_RenderObjects;
    c = renObjects.size();
    for(u32 i = 0; i < c; ++i)
    {
        RenderSystem*& renObj = renObjects[i];

        m_mStack.PushMatrix(renObj->m_Entity.m_Transform.m_transform);
        m_mStack.PushMatrix(glm::scale(glm::mat4(1),glm::vec3(16,16,1)));
        m_GraphicsSystem.DrawRenderObject(*renObj,m_mStack.GetMatrix());
        m_mStack.PopMatrix();
        m_mStack.PopMatrix();
    }
    m_mStack.Clear();
}

void Gameplay::CreateMapObjects(std::vector<u32>& ids)
{
    for(u32 i = 0, c = ids.size(); i < c; ++i)
    {
        mEntFactory.CreateEntity(ids[i]);
    }
}
