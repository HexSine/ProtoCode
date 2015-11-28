#include "BatKernel/precompiled.h"
#include "BatKernel/matrixstack.h"

MatrixStack::MatrixStack() : m_Matrix(glm::mat4(1.0f))
{
    //ctor
}

MatrixStack::~MatrixStack()
{
    //dtor
}
void MatrixStack::PushMatrix(const glm::mat4& mat)
{
    m_Stack.push(mat);

    //TODO make sure this is ok
    m_Matrix *= mat;
}
void MatrixStack::PopMatrix()
{
    m_Matrix *= glm::inverse(m_Stack.top());
    m_Stack.pop();
}
glm::mat4 MatrixStack::GetMatrix()
{
    return m_Matrix;
}
void MatrixStack::Clear()
{
    m_Matrix = glm::mat4(1.0f);
    while(!m_Stack.empty())
    {
        m_Stack.pop();
    }
}
