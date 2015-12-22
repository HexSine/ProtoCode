#include "BatApplication/precompiled.h"
#include "BatApplication/Map/entityfactory.h"

EntityFactory::EntityFactory()
{
    //ctor
}

EntityFactory::~EntityFactory()
{
    //dtor
}

Entity* EntityFactory::CreateEntity(u32 id)
{
    switch(id)
    {
    case 1:
        {
            Entity bat;
            m_Entities.push_back(bat);
        }
    case 2:
        {
        }
    }
}
