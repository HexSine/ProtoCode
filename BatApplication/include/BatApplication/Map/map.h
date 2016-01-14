#ifndef MAP_H
#define MAP_H


class Layer
{
public:
    std::vector<u32> m_Tiles;
    u32 m_Type;
    u32 m_TileSetID;
};
class TileSet
{
public:
    u32 m_firstgid;
    std::string m_image;
    u32 m_imageheight;
    u32 m_imagewidth;
    u32 m_margin;
    std::string m_name;
    u32 m_spacing;
    u32 m_tileheight;
    u32 m_tilewidth;
};
class Tile
{
public:
    u32 m_id;
    glm::vec3 m_pos;
};
class Map : public Resource
{
    public:
        Map(std::string path);
        virtual ~Map();
        void Init();
        void GenerateLayerMesh(Layer& layer, RenderObject& entity);
        void GetObjectIDs(Layer& layer, std::vector<u32>& ids);

        u32 m_Width;
        u32 m_Height;
        u32 m_tWidth;
        u32 m_tHeight;
        std::vector<TileSet> m_TileSets;
        std::vector<Layer> m_Layers;
};



#endif // MAP_H
