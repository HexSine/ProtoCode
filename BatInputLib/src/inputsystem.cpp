#include "BatInputLib/precompiled.h"
#include "BatInputLib/inputcontext.h"
#include "BatInputLib/inputsystem.h"


InputState* InputSystem::p_State = NULL;
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
void InputSystem::SetInputState(InputState* state)
{
    p_State = state;
}
void InputSystem::UpdateButtons()
{
    if(p_State)
    {
        KeyMap::iterator itEnd = p_State->m_KeyMap.end();
        for(KeyMap::iterator iter = p_State->m_KeyMap.begin(); iter != itEnd;++iter)
        {
            keyState& state= (*iter).second;
            const u32& key = (*iter).first;

            u32 glState = glfwGetKey(p_win,key);
            if(glState == GLFW_PRESS)
            {
                if(state & keyState::kDown)
                {
                    state = keyState::kDown;
                }
                else
                {
                    state = keyState::kDownPress;
                }
            }
            else if (glState == GLFW_RELEASE)
            {
                if(state & keyState::kDown)
                {
                    state = keyState::kRelease;
                }
                else
                {
                    state = keyState::kInvalid;
                }
            }


        }
    }
}

bool InputSystem::GetButton(u32 key)
{
    return true;
}
bool InputSystem::GetButtonDown(u32 key)
{
    bool ret = false;
    if(p_State)
    {
        KeyMap::iterator iter = p_State->m_KeyMap.find(key);
        if(iter != p_State->m_KeyMap.end())
        {
            ret = (*iter).second & keyState::kPress;
        }
    }
    return ret;
}
bool InputSystem::GetButtonUp(u32 key)
{
    return true;
}
