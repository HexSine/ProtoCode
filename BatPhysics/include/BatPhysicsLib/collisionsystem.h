#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

class Entity;
class BoxCollider;
struct PointInfo
{
    bool m_isStatic;
    BoxCollider* m_Collider;
    Entity* m_Entity;
};
class CollisionSystem
{
    public:
        CollisionSystem();
        virtual ~CollisionSystem();
        void AddObject(Entity* collider,bool isStatic);
        bool CheckPoint(glm::vec3 point);
        bool CheckPoint(glm::vec3 point,PointInfo* info);

    protected:
        std::vector<Entity*> m_StaticColliders;
        std::vector<Entity*> m_DynamicColliders;
    private:
};

#endif // COLLISIONSYSTEM_H
