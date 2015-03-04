#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H


class render_object
{
    public:
        render_object();
        virtual ~render_object();
    protected:
        u32 m_vertexID;
    private:
};

#endif // RENDER_OBJECT_H
