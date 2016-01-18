#include "BatKernel/precompiled.h"
#include "BatKernel/entity.h"
#include "BatKernel/system.h"

SystemMap System::m_Systems;

System::System(typeid_t systemID, Entity& entity) : m_Entity(entity), m_ID(systemID)
{
    m_Systems[systemID].push_back(this);
}

System::~System()
{
    SystemVector& sysVec = m_Systems[m_ID];
    SystemVector::iterator iter = std::remove(sysVec.begin(),sysVec.end(),this);
    sysVec.erase(iter,sysVec.end());
}

void System::Init()
{
}

void System::Update()
{
}

void System::Terminate()
{
}
void System::UpdateAllSystems()
{
    SystemMap::iterator iEnd = m_Systems.end();
    for(SystemMap::iterator iter = m_Systems.begin();iter != iEnd;++iter)
    {
        SystemVector sysVec = iter->second;
        for(u32 i = 0, c = sysVec.size(); i < c; ++i)
        {
            sysVec[i]->Update();
        }
    }
}
