#ifndef IGRAPHICSSYSTEM_H
#define IGRAPHICSSYSTEM_H


class IGraphicsSystem
{
    public:
        IGraphicsSystem();
        virtual ~IGraphicsSystem();

        virtual void Initialize();
        virtual void DrawRenderObject(const RenderObject& target,glm::mat4 matrix);
        virtual void SetTexture(u32 TexID);
        virtual void SetProgram(u32 ProgramID);
        virtual void SetVertexBuffer(u32 VertexBufferID);
        virtual void SetIndexBuffer(u32 IndexBufferID);
        static virtual u32 LoadProgram(const char* vertex_file_path, const char* fragment_file_path);
    protected:
    private:
};

#endif // IGRAPHICSSYSTEM_H
