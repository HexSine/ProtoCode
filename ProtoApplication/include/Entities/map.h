#ifndef MAP_H
#define MAP_H

#include <ProtoEngine.h>
class Map
{
    public:
        Map(std::string path);
        virtual ~Map();
        void SetMapSize(u32 width, u32 height);
        void SetTileSize(u32 width, u32 height);
        void SetTileSetCount(u32 count);
        void SetTiles(u32* tileID);
        void Init();

        u32 m_Width;
        u32 m_Height;
        u32 m_tWidth;
        u32 m_tHeight;

        RenderObject m_Renderable;
        u32* p_Tiles;
};

#endif // MAP_H
