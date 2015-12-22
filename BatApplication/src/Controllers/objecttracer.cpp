#include "objecttracer.h"

ObjectTracer::ObjectTracer(Transform& target, Transform& tracer, glm::vec3 offset) : m_Target(target), m_Tracer(tracer), m_Offset(offset)
{
}
ObjectTracer::ObjectTracer(Transform& target, Transform& tracer) : m_Target(target), m_Tracer(tracer)
{
}

ObjectTracer::~ObjectTracer()
{
    //dtor
}
void ObjectTracer::Update()
{
    glm::vec3 position = m_Target.GetPosition();
    m_Tracer.m_transform = glm::lookAt(position + m_Offset,position,glm::vec3(0,1,0));
}
