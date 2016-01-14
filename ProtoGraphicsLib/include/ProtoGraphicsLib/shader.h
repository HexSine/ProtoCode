#ifndef SHADER_H
#define SHADER_H

#include "BatKernel/Resource/resource.h"
class Shader : public Resource
{
    public:
        Shader(std::string path);
        virtual ~Shader();

        u32 m_ProgramID;
};
#endif // SHADER_H
