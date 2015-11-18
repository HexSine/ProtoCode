#ifndef TRANSFORM_H
#define TRANSFORM_H

//File: transform.h
//Description: Transform keeps track of the position, rotation, and scale of an object
//Copywrite: Nathan Boyes - 19/03/2015

class Transform
{
    public:
        Transform();
        virtual ~Transform();
        void Translate(const glm::vec3& translation);
        void Translate(float x, float y, float z);
        void Scale(float x, float y, float z);
        //void Rotate(float x, float y, float z);
        glm::vec3 GetPosition();
        void SetPosition(const glm::vec3& pos);
        glm::mat4 m_transform;
    protected:
        glm::vec3 m_pos;
        u8 flags;
    private:
};

#endif // TRANSFORM_H
