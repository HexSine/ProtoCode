#ifndef MATERIAL_H
#define MATERIAL_H


class Shader;
class Material
{
    public:
        Material();
        virtual ~Material();

        u32 m_ProgramID;
        u32 m_TextureID;
    protected:
    private:
};

#endif // MATERIAL_H
