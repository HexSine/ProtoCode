#include "BatApplication/precompiled.h"
#include "BatApplication/Map/entityfactory.h"
#include "BatApplication/Player/character.h"
#include "BatApplication/Player/playercontroller.h"
#include "BatApplication/Controllers/objecttracer.h"
EntityFactory::EntityFactory(ResourceManager& resSystem) : m_ResourceData(resSystem)
{
    m_cam.SetView(glm::vec3(256,-128,10),glm::vec3(256,-128,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);
}

EntityFactory::~EntityFactory()
{
    SafeDeleteVector(m_Entities);
    SafeDeleteVector(m_Systems);
}

RenderedEntity* EntityFactory::CreateEntity(u32 id, glm::vec3 position)
{
    switch(id)
    {
    case 1:
        {
            //Create da bat
            Character* bat = new Character();
            bat->m_Transform.SetPosition(position);

            //Give it some render information
            RenderSystem* renObj = bat->AddSystem<RenderSystem>();
            renObj->p_Material = m_ResourceData.GetPtr<Material>("Data/Materials/Gameplay/BatMat.mat");
            renObj->p_Mesh = m_ResourceData.GetPtr<Mesh>("Data/Models/quad.obj");

            //Add CameraTracer System
            ObjectTracer* camTracer = m_cam.AddSystem<ObjectTracer>();
            camTracer->m_Target = &bat->m_Transform;
            camTracer->m_Offset = glm::vec3(0,0,10);

            //Make it so we can move da bat
            bat->AddSystem<PlayerController>();

            m_Entities.push_back(bat);
        }
    case 2:
        {
        }
    }
    return NULL;
}
RenderedEntity* EntityFactory::CreateEntity(u32 id)
{
    return CreateEntity(id,glm::vec3(0));
}
