#include "BatKernel/precompiled.h"

#include "BatKernel/transform.h"
#include "BatKernel/entity.h"

Entity::Entity() : m_Active(true), m_Systems()
{
    //ctor
}

Entity::~Entity()
{
    for(SystemMap::iterator iter = m_Systems.begin(), iEnd = m_Systems.end(); iter != iEnd; ++iter)
    {
        SafeDeleteVector(iter->second);
    }
    m_Systems.clear();
}
