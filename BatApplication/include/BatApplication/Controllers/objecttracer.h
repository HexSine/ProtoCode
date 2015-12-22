#ifndef OBJECTTRACER_H
#define OBJECTTRACER_H


class ObjectTracer
{
    public:
        ObjectTracer(Transform& target, Transform& tracer, glm::vec3 offset);
        ObjectTracer(Transform& target, Transform& tracer);
        virtual ~ObjectTracer();
        void Update();
    protected:
        Transform& m_Target;
        Transform& m_Tracer;
        glm::vec3 m_Offset;
    private:
};

#endif // OBJECTTRACER_H
