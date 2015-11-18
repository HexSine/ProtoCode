#ifndef INPUT_H
#define INPUT_H

#include "BatKernel/ibatinput.h"
class Input : public IBatInput
{
    public:
        Input();
        ~Input();
        bool Init(GLFWwindow* _win);
        virtual bool GetKey(s32 kycode);
        virtual bool GetKeyDown(s32 keycode);
        virtual bool GetKeyUp(s32 keycode);
        virtual s32 GetKeyState(s32 keycode);
    protected:
        GLFWwindow* p_win;//g
};

#endif // INPUT_H
