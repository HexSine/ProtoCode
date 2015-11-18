#ifndef TEXTURE_H
#define TEXTURE_H


class Texture
{
    public:
        Texture(std::string path);
        virtual ~Texture();

        u32 m_TextureID;
    protected:
    private:
};

#endif // TEXTURE_H
