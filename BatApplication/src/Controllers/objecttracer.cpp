#include "BatApplication/Controllers/objecttracer.h"

ObjectTracer::ObjectTracer(Entity& entity) : System(type_id<ObjectTracer>(),entity), m_Tracer(entity.m_Transform)
{
}

ObjectTracer::~ObjectTracer()
{
    //dtor
}
void ObjectTracer::Update()
{
    if(m_Target)
    {
        glm::vec3 position = m_Target->GetPosition();
        m_Tracer.m_transform = glm::lookAt(position + m_Offset,position,glm::vec3(0,1,0));
    }
}
