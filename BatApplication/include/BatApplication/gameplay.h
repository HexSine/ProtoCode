#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "BatApplication/Controllers/objecttracer.h"
#include "BatApplication/Player/character.h"
#include "BatApplication/Map/map.h"
#include "BatApplication/Player/playercontroller.h"

#include "BatApplication/Map/entityfactory.h"

class Gameplay : public BaseState
{
    public:
        Gameplay(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc);
        virtual ~Gameplay();

        virtual void Load();
        virtual void Unload();
        virtual int Update(float deltaTime);
        virtual void Render();

        void SpawnLayer(Layer& layer);

        void CreateMapObjects(std::vector<u32>& ids);

        Entity m_background;

        MatrixStack m_mStack;
        InputState m_InputState;

        //Entitys
        EntityFactory mEntFactory;
        std::vector<Entity*> m_Renderables;
        Map* p_Map;

    protected:
    private:
};

#endif // FRONTEND_H
