#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H


class BoxCollider
{
    public:
        BoxCollider();
        virtual ~BoxCollider();


        glm::vec2 m_Size;
        glm::vec2 m_Center;
    protected:
    private:
};

#endif // BOXCOLLIDER_H
