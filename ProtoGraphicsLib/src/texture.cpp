#include "ProtoGraphicsLib/texture.h"

Texture::Texture(std::string path)
{
    m_TextureID = SOIL_load_OGL_texture(path.c_str(),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_TextureID);
}
