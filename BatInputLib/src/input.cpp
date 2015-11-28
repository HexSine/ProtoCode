#include "BatInputLib/precompiled.h"
#include "BatInputLib/input.h"

Input::Input() : p_win(NULL)
{
}
Input::~Input()
{
}
bool Input::Init(GLFWwindow* _win)
{
    p_win = _win;
    return _win != NULL;
}
bool Input::GetKey(s32 keycode)
{
    assert(p_win != NULL);
    return glfwGetKey(p_win,keycode) == GLFW_PRESS;
}
bool Input::GetKeyDown(s32 keycode)
{
    assert(p_win != NULL);
    return glfwGetKey(p_win,keycode) == GLFW_PRESS;
}
bool Input::GetKeyUp(s32 keycode)
{
    assert(p_win != NULL);
    return glfwGetKey(p_win,keycode) == GLFW_RELEASE;
}
s32 Input::GetKeyState(s32 keycode)
{
    assert(p_win != NULL);
    return glfwGetKey(p_win,keycode);
}
