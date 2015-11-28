#include "ProtoEngine/precompiled.h"
#include "ProtoEngine/Physics/collisionsystem.h"
#include "ProtoEngine/Physics/boxcollider.h"
#include "ProtoEngine/entity.h"
CollisionSystem::CollisionSystem()
{
    //ctor
}

CollisionSystem::~CollisionSystem()
{
    //dtor
}
void CollisionSystem::AddObject(Entity* object,bool isStatic)
{
    if(isStatic)
    {
        m_StaticColliders.push_back(object);
    }
    else
    {
        m_DynamicColliders.push_back(object);
    }
}
bool CollisionSystem::CheckPoint(glm::vec3 point)
{
    for(std::vector<Entity*>::iterator iter = m_StaticColliders.begin(); iter != m_StaticColliders.end();++iter)
    {
        Entity* object = (*iter);
        glm::vec3 boxPos = object->m_Transform.GetPosition();
        BoxCollider* box = object->p_Collider;
        if(point.x < boxPos.x + box->m_Center.x + box->m_Size.x/2 && point.x > boxPos.x + box->m_Center.x - box->m_Size.x/2
           && point.y < boxPos.y + box->m_Center.y + box->m_Size.y/2 && point.y > boxPos.y + box->m_Center.y - box->m_Size.y/2)
        {
            return true;
        }
    }
    return false;
}
bool CollisionSystem::CheckPoint(glm::vec3 point,PointInfo* info)
{
    for(std::vector<Entity*>::iterator iter = m_StaticColliders.begin(); iter != m_StaticColliders.end();++iter)
    {
        Entity* object = (*iter);
        glm::vec3 boxPos = object->m_Transform.GetPosition();
        BoxCollider* box = object->p_Collider;
        if(point.x < boxPos.x + box->m_Center.x + box->m_Size.x/2 && point.x > boxPos.x + box->m_Center.x - box->m_Size.x/2
           && point.y < boxPos.y + box->m_Center.y + box->m_Size.y/2 && point.y > boxPos.y + box->m_Center.y - box->m_Size.y/2)
        {
            info->m_Entity = object;
            info->m_isStatic= true;
            info->m_Collider = box;
            return true;
        }
    }
    for(std::vector<Entity*>::iterator iter = m_DynamicColliders.begin(); iter != m_DynamicColliders.end();++iter)
    {
        Entity* object = (*iter);
        glm::vec3 boxPos = object->m_Transform.GetPosition();
        BoxCollider* box = object->p_Collider;
        if(point.x < boxPos.x + box->m_Center.x + box->m_Size.x/2 && point.x > boxPos.x + box->m_Center.x - box->m_Size.x/2
           && point.y < boxPos.y + box->m_Center.y + box->m_Size.y/2 && point.y > boxPos.y + box->m_Center.y - box->m_Size.y/2)
        {
            info->m_Entity = object;
            info->m_isStatic= false;
            info->m_Collider = box;
            return true;
        }
    }
    return false;
}
