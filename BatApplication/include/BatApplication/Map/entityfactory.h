#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "BatApplication/Entity/renderedentity.h"
class EntityFactory
{
    public:
        EntityFactory(ResourceManager& resSystem);
        virtual ~EntityFactory();

        RenderedEntity* CreateEntity(u32 id, glm::vec3 position);
        RenderedEntity* CreateEntity(u32 id);

        Camera m_cam;
        std::vector<RenderObject*> m_RenderObjects;
        std::vector<System*> m_Systems;
        std::vector<RenderedEntity*> m_Entities;
        ResourceManager& m_ResourceData;
    private:
};

#endif // ENTITYFACTORY_H
