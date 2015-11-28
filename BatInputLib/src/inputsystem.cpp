#include "BatInputLib/precompiled.h"
#include "BatInputLib/inputcontext.h"
#include "BatInputLib/inputsystem.h"
InputSystem::InputSystem() : p_win(NULL)
{
    //ctor
}


InputSystem::~InputSystem()
{
    //dtor
}


bool InputSystem::Initialize(GLFWwindow* _win)
{
    p_win = _win;
    return _win != NULL;
}


InputContainer InputSystem::HandleInput()
{
    InputContext* context = m_ContextStack.top();
    context->Poll(p_win);
    return InputContainer();
}
