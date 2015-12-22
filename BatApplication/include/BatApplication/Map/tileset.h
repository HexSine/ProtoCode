#ifndef TILESET_H
#define TILESET_H


class Tileset
{
    public:
        Tileset();
        virtual ~Tileset();

    protected:
        u32 m_FirstGID;
        u32 m_Width,m_Height;
        u32 m_TileWidth, m_TileHeight;
        std::string imagePath;
    private:
};

#endif // TILESET_H
