#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/material.h"

Material::Material(std::string path)
{
    std::ifstream MaterialStream(path,std::ios::in);
    if(!MaterialStream.is_open())
    {
        printf("Unable to open shader at path %s\n",path.c_str());
    }
    //Get The Shader Pieces
    getline(MaterialStream,m_TextureID);
    getline(MaterialStream,m_ProgramID);
    MaterialStream.close();
}

Material::~Material()
{
    //dtor
}
