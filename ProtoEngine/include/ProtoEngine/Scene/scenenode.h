#ifndef SCENENODE_H
#define SCENENODE_H

class Entity;
class SceneNode
{
    public:
        SceneNode();
        virtual ~SceneNode();
        void AddNode(Entity* entity);
    protected:
        Entity* entity;
        std::list<SceneNode> m_Nodes;
    private:
};

#endif // SCENENODE_H
