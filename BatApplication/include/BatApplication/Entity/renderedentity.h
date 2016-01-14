#ifndef RENDEREDENTITY_H
#define RENDEREDENTITY_H


class RenderedEntity : public Entity
{
    public:
        RenderedEntity();
        virtual ~RenderedEntity();
        RenderObject m_RenderObject;
    protected:
    private:
};

#endif // RENDEREDENTITY_H
