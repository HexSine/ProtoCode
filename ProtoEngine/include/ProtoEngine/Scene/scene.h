#ifndef SCENE_H
#define SCENE_H

#include "ProtoEngine\Scene\scenenode.h"
class Scene
{
    public:
        Scene();
        virtual ~Scene();
    protected:
        void CreateEntity();

        SceneNode m_SceneRoot;

};

#endif // SCENE_H
