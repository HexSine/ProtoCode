#ifndef GAMEPLAY_H
#define GAMEPLAY_H


class Gameplay : public BaseState
{
    public:
        Gameplay(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,GameContext& gc);
        virtual ~Gameplay();

        virtual void Load();
        virtual void Unload();
        virtual int Update(float deltaTime);
        virtual void Render();

        RenderObject m_background;
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
