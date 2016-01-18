#ifndef ENTITY_H
#define ENTITY_H

#include "BatKernel/object.h"
#include "BatKernel/system.h"
class Entity : public Object
{
    public:
        Entity();
        virtual ~Entity();

        virtual void Init()
        {
        };
        virtual void Update(){};
        virtual void Terminate(){};

        template <typename T>
        T* AddSystem();
        template <typename T>
        T* GetSystem();

        bool m_Active;
        Transform m_Transform;
        SystemMap m_Systems;
    protected:
    private:
};


template <typename T>
T* Entity::AddSystem()
{
    T* t = new T(*this);
    m_Systems[type_id<T>()].push_back(t);
    return t;
}

template <typename T>
T* Entity::GetSystem()
{
    SystemMap::iterator iter = m_Systems.find(type_id<T>());
    if(iter != m_Systems.end())
    {
        SystemVector& vec = iter->second;
        if(vec.size() > 0)
        {
            return static_cast<T*>(vec[0]);
        }
    }
    return NULL;

}

#endif // ENTITY_H
