#ifndef INCLUDED_GAME_PLAY
#define INCLUDED_GAME_PLAY


#include "ProtoEngine/ProtoEngine.h"

#include "BaseState.h"
#include "Entities\Characters\knight.h"
#include "Entities\Characters\archer.h"
#include "Entities\Map\tile_box.h"
#include "Entities\Map\background.h"
#include "Entities\map.h"

class GamePlay : public BaseState
{
public:
	GamePlay(GameContext& gc);
	virtual ~GamePlay();

	virtual void Load();
	virtual void Unload();
	virtual int Update(float deltaTime);
	virtual void Render();

protected:

	void LoadMaterials();
	void LoadMap();

	Scene m_Scene;
    MatrixStack m_MatStack; // MAD STACKS BROSEPH

    CollisionSystem m_CollisionSys;
	GraphicsSystem m_GraphicsSys;

	UpdateContext m_UpdateContext;

    u32 m_ArrIndex;
    Projectile* GetArrow();
    Camera m_cam;

    Map m_Map;
    //Materials
    Material m_KnightMaterial;
    Material m_ArcherMaterial;
    Material m_TileMaterial;
    Material m_BackGroundMaterial;
    Material m_ArrowMaterial;
    Material m_TerrainMaterial;


    Background m_bg;
    Archer m_Bat;
    Archer m_Archer2;
    u32 m_ArrCount;
    Projectile m_Arrows[20];
    const u32 m_tileCount;
    tile_box m_Tiles[20];

    tile_box m_Platform1[2];
    tile_box m_Platform2[2];

};

#endif
