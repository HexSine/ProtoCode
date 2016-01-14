#ifndef MATERIAL_H
#define MATERIAL_H

#include "BatKernel/Resource/resource.h"
class Shader;
class Material : public Resource
{
    public:
        Material(std::string path);
        virtual ~Material();

        std::string m_ProgramID;
        std::string m_TextureID;
    protected:
    private:
};

#endif // MATERIAL_H
