#include "ProtoGraphicsLib/precompiled.h"
#include "ProtoGraphicsLib/camera.h"

Camera::Camera()
{
    //ctor
}
Camera::~Camera()
{
    //dtor
}
void Camera::SetView(glm::vec3 position, glm::vec3 target, glm::vec3 up)
{
    m_Projection = glm::perspective(45.0f,4.0f/3.0f,0.1f,100.0f);
    m_Transform.m_transform = glm::lookAt(position,target,up );
}
void Camera::SetPerspective(float _fov,float _aspect,float _near, float _far)
{
    m_Projection = glm::perspective(_fov,_aspect,_near,_far);
}
void Camera::SetOrtho(glm::vec3 Position, float width, float height,float _near, float _far)
{
    m_Projection = glm::ortho(Position.x - width * 0.5f,Position.x + width * 0.5f,Position.y - height * 0.5f,Position.y + height * 0.5f,_near,_far);
}
