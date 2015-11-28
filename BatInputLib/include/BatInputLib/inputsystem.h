#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

class InputSystem : public IBatInput
{
    public:
        InputSystem();
        virtual ~InputSystem();
        virtual bool Initialize(GLFWwindow* _win);
        InputContainer HandleInput();
        void PushContext(InputContext* context);
        void PopContext();

    protected:
        std::stack<InputContext*> m_ContextStack;
        GLFWwindow* p_win;//g
    private:
};

#endif // INPUTSYSTEM_H
