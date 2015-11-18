#include "map.h"

Map::Map() : p_Tiles(NULL), m_Width(0), m_Height(0),m_tWidth(0),m_tHeight(0)
{
    //ctor
}

Map::~Map()
{
    SafeDeleteArray(p_Tiles);
}
void Map::Init()
{
    m_Renderable.p_Mesh = new Quad(32.0f,32.0f);
    m_Renderable.Init();

    float t = 32.0f/256.0f;
    m_Renderable.m_Tile = glm::vec2(t,t);
    m_Renderable.m_Offset = glm::vec2(0.0f,224.0f/256.0f);

}
void Map::SetMapSize(u32 width, u32 height)
{
    m_Width = width;
    m_Height = height;
    SafeDeleteArray(p_Tiles);
    p_Tiles = new u32[width*height];
}
void Map::SetTiles(u32* tileID)
{
    u32* id = tileID;
    u32* tile = p_Tiles;
    for(u32 y = 0; y < m_Height; ++y)
    {
        for(u32 x = 0; x < m_Width; ++x)
        {
            *tile = *id;
            ++tile;
            ++id;
        }
    }
}
void Map::SetTileSize(u32 width, u32 height)
{
    m_tWidth = width;
    m_tHeight = height;
}
