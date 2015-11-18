#include "State/GamePlay.h"

//Entities
#include "jsonmaploader.h"
#include <assert.h>
GamePlay::GamePlay(GameContext& gc)
	: BaseState(gc), m_ArrIndex(0), m_ArrCount(20), m_tileCount(20), m_UpdateContext(m_CollisionSys)
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::Load()
{
    m_UpdateContext.m_CollisionSystem = m_CollisionSys;
    LoadMaterials();
    LoadMap();


    m_Map.m_Renderable.p_Material = &m_TerrainMaterial;
    m_Map.Init();

    m_bg.m_Renderable.p_Material = &m_BackGroundMaterial;
    m_bg.Init();


    m_Bat.m_Renderable.p_Material = &m_ArcherMaterial;
    m_Bat.m_PlayerID = 1;
    m_Bat.Init();
    m_Bat.m_Renderable.m_Offset = glm::vec2(256,0);
    m_CollisionSys.AddObject(&m_Bat,false);

    m_Archer2.m_Renderable.p_Material = &m_ArcherMaterial;
    m_Archer2.m_PlayerID = 2;
    m_Archer2.Init();
    m_CollisionSys.AddObject(&m_Archer2,false);

    Projectile* arr = &m_Arrows[0];
    for(int i = 0; i < m_ArrCount;++i)
    {
        arr->m_Renderable.p_Material = &m_ArrowMaterial;
        arr->m_Active = false;
        arr->Init();
        ++arr;
    }

    /*u32* maptile = m_Map.p_Tiles;
    for(s32 y = 0; y < m_Map.m_Height;++y)
    {
        for(s32 x = 0; x < m_Map.m_Width;++x)
        {
            if(*maptile == 2)
            {
                Entity* collider = new Entity();
                collider->p_Collider = new BoxCollider();
                collider->p_Collider->m_Size = glm::vec2(32,32);
                glm::vec3 vec = glm::vec3(x * (f32)m_Map.m_tWidth - (f32)m_Map.m_tWidth*(f32)m_Map.m_Width*0.5f,y * (f32)m_Map.m_tHeight - (f32)m_Map.m_tHeight*(f32)m_Map.m_Height + (f32)m_Map.m_tHeight*(f32)m_Map.m_Height*0.5f,0.0f);
                collider->m_Transform.SetPosition(vec);
                m_CollisionSys.AddObject(collider,true);
            }
            ++maptile;
        }
    }*/

    m_cam.SetView(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
    m_cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);


    m_GraphicsSys.SetProgram(m_ArcherMaterial.m_ProgramID);

}
void GamePlay::Unload()
{
    glDeleteTextures(1,&m_ArcherMaterial.m_TextureID);
    glDeleteTextures(1,&m_ArcherMaterial.m_TextureID);
    glDeleteTextures(1,&m_BackGroundMaterial.m_TextureID);
    glDeleteProgram(m_ArcherMaterial.m_ProgramID);

    m_Bat.Terminate();
    m_Archer2.Terminate();
}
int GamePlay::Update(float deltaTime)
{
	int nextState = GameState::Invalid;

	m_Bat.Update(deltaTime,m_UpdateContext);
	m_Archer2.Update(deltaTime,m_UpdateContext);


    Projectile* arr = &m_Arrows[0];
	for(int i = 0; i < m_ArrCount;++i)
    {
        if(arr->m_Active == true)
        {
            arr->Update(deltaTime);
        }
        ++arr;
    }

	return nextState;
}
void GamePlay::Render()
{
    m_MatStack.PushMatrix(m_cam.m_Projection);
    m_MatStack.PushMatrix(m_cam.m_View);


    //Draw the Background;
    m_MatStack.PushMatrix(m_bg.m_Transform.m_transform);
    m_GraphicsSys.DrawRenderObject(m_bg.m_Renderable,m_MatStack.GetMatrix());
    m_MatStack.PopMatrix();

    Projectile* arr = &m_Arrows[0];
    for(int i = 0; i < m_ArrCount;++i)
    {
        if(arr->m_Active == true)
        {
            m_MatStack.PushMatrix(arr->m_Transform.m_transform);
            m_GraphicsSys.DrawRenderObject(arr->m_Renderable,m_MatStack.GetMatrix());
            m_MatStack.PopMatrix();
        }
        ++arr;
    }


    s32 mapWidth = m_Map.m_Width;
    glm::mat4 MapMVP = m_MatStack.GetMatrix();
    u32* maptile = m_Map.p_Tiles;
    MapMVP = glm::translate(MapMVP,glm::vec3(-(f32)m_Map.m_tWidth * (f32)m_Map.m_Width * 0.5f +(f32)m_Map.m_tWidth * 0.5f ,(f32)m_Map.m_tHeight * (f32)m_Map.m_Height * 0.5f -(f32)m_Map.m_tHeight * 0.5f,0));
    for(s32 y = 0; y < m_Map.m_Height;++y)
    {
        for(s32 x = 0; x < mapWidth;++x)
        {
            m_Map.m_Renderable.m_Frame.x = *maptile - 1;
            m_GraphicsSys.DrawRenderObject(m_Map.m_Renderable,MapMVP);
            MapMVP = glm::translate(MapMVP,glm::vec3(m_Map.m_tWidth,0,0));
            ++maptile;
        }
        MapMVP = glm::translate(MapMVP,glm::vec3(-mapWidth * (s32)m_Map.m_tWidth,-(s32)m_Map.m_tHeight,0));
    }

    m_MatStack.PushMatrix(m_Bat.m_Transform.m_transform);
    m_GraphicsSys.DrawRenderObject(m_Bat.m_Renderable,m_MatStack.GetMatrix());
    m_MatStack.PopMatrix();

    m_MatStack.PushMatrix(m_Archer2.m_Transform.m_transform);
    m_GraphicsSys.DrawRenderObject(m_Archer2.m_Renderable,m_MatStack.GetMatrix());
    m_MatStack.PopMatrix();





    m_MatStack.Clear();
}

void GamePlay::LoadMap()
{
    JSONMapLoader MapLoader;
    MapLoader.Parse("./Data/Maps/TestMap.json");
    m_Map.SetMapSize(MapLoader.m_w,MapLoader.m_h);
    m_Map.SetTileSize(MapLoader.m_tw,MapLoader.m_th);
    m_Map.SetTiles(MapLoader.p_id);
    m_TerrainMaterial.m_TextureID = SOIL_load_OGL_texture(MapLoader.m_ImagePath.c_str(),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    m_TerrainMaterial.m_ProgramID = m_ArcherMaterial.m_ProgramID;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize
}

void GamePlay::LoadMaterials()
{

    m_ArcherMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/Characters/battesheet.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    m_ArcherMaterial.m_ProgramID = GraphicsSystem::LoadProgram("./TexturedVertexShader.glsl","./TexturedFragmentShader.glsl");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    m_ArrowMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/Entities/arrow.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    m_ArrowMaterial.m_ProgramID = m_ArcherMaterial.m_ProgramID;

    m_BackGroundMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/Map/BackGround/background.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    //TODO Fix startmaterial assignment
    m_BackGroundMaterial.m_ProgramID = m_ArcherMaterial.m_ProgramID;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize

    m_TileMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/Map/block_tile.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    m_TileMaterial.m_ProgramID = GraphicsSystem::LoadProgram("./TexturedVertexShader.glsl","./TexturedFragmentShader.glsl");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize
}
Projectile* GamePlay::GetArrow()
{
    Projectile* arrow = &m_Arrows[0];
    int i = 0;
    while(arrow->m_Active == true && i < m_ArrCount)
    {
        ++i;
        ++arrow;
    }
    if(i == m_ArrCount)
    {
        return NULL;
    }
    arrow->m_Active = true;
    return arrow;
}
