#ifndef CAMERA_H
#define CAMERA_H


class Camera : public Entity
{
    public:
        Camera();
        virtual ~Camera();

        void SetView(glm::vec3 position, glm::vec3 target, glm::vec3 up);
        void SetPerspective(float fov,float aspect,float near, float far);
        void SetOrtho(glm::vec3 Position, float width, float height,float near, float far);
        glm::mat4x4 m_Projection;
};

#endif // CAMERA_H
