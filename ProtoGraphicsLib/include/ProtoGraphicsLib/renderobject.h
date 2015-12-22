#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H


class Camera;
class Mesh;
class Material;

class RenderObject : public IBatComponent
{
    public:
        RenderObject();
        virtual ~RenderObject();

        void Init();

        Mesh* p_Mesh;
        Material* p_Material;
        glm::vec2 m_Offset;
        glm::vec2 m_Tile;
        glm::ivec2 m_Frame;
};

#endif // RENDEROBJECT_H
