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

        void MoveUp();
        void MoveDown();

        RenderObject m_background;
        RenderObject m_cursor;
        Camera m_cam;

        Material m_BGMaterial;
        Material m_CursorMaterial;

        u32 m_CursorIndex;
        glm::vec3 m_CursorPositions[3];
        Entity m_Cursor;

        ResourceManager<Texture> textureManager;
        ResourceManager<Shader> shaderManager;
        ResourceManager<Mesh> meshManager;

        MatrixStack m_mStack;
        InputState m_InputState;

    protected:
    private:
};

#endif // FRONTEND_H
