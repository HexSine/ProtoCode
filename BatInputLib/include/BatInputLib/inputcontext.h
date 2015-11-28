#ifndef INPUTCONTEXT_H
#define INPUTCONTEXT_H

enum keyState
{
    kInvalid,
    kHold,
    kPress,
    kRelease
};

class InputContext
{
    public:
        InputContext(std::string path);
        virtual ~InputContext();
        void Poll(GLFWwindow* _win);
    protected:
        std::map<u32,keyState> m_KeyMap;
    private:
};

#endif // INPUTCONTEXT_H
