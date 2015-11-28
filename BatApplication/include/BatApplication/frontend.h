#ifndef FRONTEND_H
#define FRONTEND_H

#include "ProtoEngine\protoengine.h"
class FrontEnd : public BaseState
{
    public:
        FrontEnd(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,GameContext& gc);
        virtual ~FrontEnd();

        virtual void Load();
        virtual void Unload();
        virtual int Update(float deltaTime);
        virtual void Render();

        RenderObject m_background;
        RenderObject m_cursor;
        Camera m_cam;

        Material m_BGMaterial;
        Material m_CursorMaterial;

        glm::vec3 m_CursorPositions[2];
        Entity m_Cursor;

        ResourceManager<Texture> textureManager;
        ResourceManager<Shader> shaderManager;
        ResourceManager<Mesh> meshManager;

        MatrixStack m_mStack;
    protected:
    private:
};

#endif // FRONTEND_H
