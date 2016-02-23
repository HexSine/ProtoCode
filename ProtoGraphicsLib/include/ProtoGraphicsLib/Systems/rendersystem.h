#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "BatKernel/system.h"

class Camera;
class Mesh;
class Material;


class RenderSystem : public System
{
    public:
        RenderSystem(Entity& entity);
        virtual ~RenderSystem();

        Mesh* p_Mesh;
        Material* p_Material;
        glm::vec2 m_Offset;
        glm::vec2 m_Tile;
        glm::ivec2 m_Frame;

    protected:
    private:
};

#endif // RENDERSYSTEM_H
