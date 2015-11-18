#include "ProtoEngine/precompiled.h"
#include "ProtoEngine/transform.h"

Transform::Transform() : m_transform(1.0f), flags(0)

{
    //ctor
}

Transform::~Transform()
{
    //dtor
}

void Transform::Translate(const glm::vec3& translation)
{
    m_transform[3][0] += translation.x;
    m_transform[3][1] += translation.y;
    m_transform[3][2] += translation.z;
    flags &= ~0x1;
}
void Transform::Translate(float x, float y, float z)
{
    m_transform[3][0] += x;
    m_transform[3][1] += y;
    m_transform[3][2] += z;
    flags &= ~0x1;
}

glm::vec3 Transform::GetPosition()
{
    if(!(flags & 0x1))
    {
        m_pos = glm::vec3(m_transform[3][0],m_transform[3][1],m_transform[3][2]);
        flags |= 0x1;
    }
    return m_pos;
}
void Transform::SetPosition(const glm::vec3& pos)
{
    m_transform[3][0] = pos.x;
    m_transform[3][1] = pos.y;
    m_transform[3][2] = pos.z;
    flags &= ~0x1;
}
