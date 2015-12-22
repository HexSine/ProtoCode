#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "BatApplication/Controllers/objecttracer.h"
#include "BatApplication/Player/character.h"
#include "BatApplication/Map/map.h"
#include "BatApplication/Player/playercontroller.h"
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
        Material m_MapMaterial;
        Material m_BatMaterial;

        ResourceManager<Texture> textureManager;
        ResourceManager<Shader> shaderManager;
        ResourceManager<Mesh> meshManager;
        ResourceManager<Map> m_MapManager;

        MatrixStack m_mStack;
        InputState m_InputState;

        //Controllers
        PlayerController m_Controller;
        ObjectTracer m_CameraController;

        //Entitys
        Map* p_Map;
        Character m_Bat;

    protected:
    private:
};

#endif // FRONTEND_H
