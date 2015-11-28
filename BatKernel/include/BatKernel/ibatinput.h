#ifndef IBATINPUT_H
#define IBATINPUT_H

class InputContainer
{

};
class IBatInput
{
    public:
        IBatInput();
        virtual ~IBatInput();

        virtual bool Initialize(GLFWwindow* _win) = 0;
        virtual InputContainer HandleInput() = 0;
        //virtual bool GetKey(s32 kycode) = 0;
        //virtual bool GetKeyDown(s32 keycode) = 0;
        //virtual bool GetKeyUp(s32 keycode) = 0;
        //virtual s32 GetKeyState(s32 keycode) = 0;
    protected:
    private:
};

#endif // IBATINPUT_H
