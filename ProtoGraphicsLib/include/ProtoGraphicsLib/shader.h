#ifndef SHADER_H
#define SHADER_H

class Shader
{
    public:
        Shader(std::string path);
        virtual ~Shader();

        u32 m_ProgramID;
};
#endif // SHADER_H
