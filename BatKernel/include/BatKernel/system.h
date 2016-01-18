#ifndef ISYSTEM_H
#define ISYSTEM_H

#include "Object.h"
class System;
class Entity;
typedef std::vector<System*> SystemVector;
typedef std::map<typeid_t,SystemVector> SystemMap;
typedef std::pair<typeid_t,SystemVector> SystemPair;
class System : public Object
{
    public:
        System(typeid_t systemId, Entity& entity);
        virtual ~System();
        virtual void Init();
        virtual void Terminate();
        virtual void Update();
        Entity& m_Entity;
        typeid_t m_ID;

        template <typename T>
        static std::vector<T*> GetSystems();
        static void UpdateAllSystems();
    protected:
        static SystemMap m_Systems;
    private:
};

template <typename T>
std::vector<T*> System::GetSystems()
{
    typeid_t type = type_id<T>();
    SystemMap::iterator iter = m_Systems.find(type);
    if(iter != m_Systems.end())
    {
        SystemVector& sysVec = iter->second;
        return VectorCast<T>(sysVec);
    }
    return std::vector<T*>();
}
#endif // ISYSTEM_H
