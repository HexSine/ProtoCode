#ifndef OBJECTTRACER_H
#define OBJECTTRACER_H


class ObjectTracer : public System
{
    public:
        ObjectTracer(Entity& entity);
        virtual ~ObjectTracer();
        virtual void Update();

        Transform* m_Target;
        glm::vec3 m_Offset;
    protected:
        Transform& m_Tracer;
    private:
};

#endif // OBJECTTRACER_H
