#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H




class InputSystem : public IBatInput
{
    public:
        InputSystem();
        virtual ~InputSystem();
        virtual bool Initialize(GLFWwindow* _win);
        virtual void SetInputState(InputState* state);
        virtual void UpdateButtons();

        virtual bool GetButton(u32 key);
        virtual bool GetButtonDown(u32 key);
        virtual bool GetButtonUp(u32 key);

    protected:

        static InputState* p_State;
        static void KeyFunction(GLFWwindow*,int,int,int,int);
        GLFWwindow* p_win;//g

    private:
};

#endif // INPUTSYSTEM_H
