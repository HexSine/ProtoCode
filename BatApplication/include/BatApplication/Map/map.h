#ifndef MAP_H
#define MAP_H


class Layer
{
public:
    std::vector<u32> m_Tiles;
    u32 m_Type;
};
class Map
{
    public:
        Map(std::string path);
        virtual ~Map();
        void Init();
        void GenerateLayerMesh(Layer& layer, RenderObject& entity);

        u32 m_Width;
        u32 m_Height;
        u32 m_tWidth;
        u32 m_tHeight;
        std::vector<Layer> m_Layers;
};



#endif // MAP_H
