#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

class MatrixStack
{
    public:
        MatrixStack();
        virtual ~MatrixStack();
        void PushMatrix(const glm::mat4& mat);
        void PopMatrix();
        glm::mat4 GetMatrix();
        void Clear();
    protected:
        std::stack<glm::mat4> m_Stack;
        glm::mat4 m_Matrix;
    private:
};

#endif // MATRIXSTACK_H
