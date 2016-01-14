#include "BatApplication/precompiled.h"
#include "BatApplication/Map/entityfactory.h"
#include "BatApplication/Player/character.h"
EntityFactory::EntityFactory(ResourceManager& resSystem) : m_ResourceData(resSystem)
{
    //ctor
}

EntityFactory::~EntityFactory()
{
    //dtor
}

RenderedEntity* EntityFactory::CreateEntity(u32 id, glm::vec3 position)
{
    switch(id)
    {
    case 1:
        {
            Character* bat = new Character();
            bat->m_RenderObject.p_Material = m_ResourceData.GetPtr<Material>("Data/Materials/Gameplay/BatMat.mat");
            bat->m_RenderObject.p_Mesh = m_ResourceData.GetPtr<Mesh>("Data/Models/quad.obj");
            bat->m_Transform.SetPosition(position);
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
