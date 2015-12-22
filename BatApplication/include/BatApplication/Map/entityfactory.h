#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "BatKernel/entity.h"
class EntityFactory
{
    public:
        EntityFactory();
        virtual ~EntityFactory();
        Entity* CreateEntity(u32 id);
    protected:
        std::vector<Entity> m_Entities;
    private:
};

#endif // ENTITYFACTORY_H
