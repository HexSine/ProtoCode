#ifndef TEXTURE_H
#define TEXTURE_H


#include "BatKernel/Resource/resource.h"
class Texture : public Resource
{
    public:
        Texture(std::string path);
        virtual ~Texture();

        u32 m_TextureID;
    protected:
    private:
};

#endif // TEXTURE_H
