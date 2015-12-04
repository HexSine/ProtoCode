#ifndef IBATINPUT_H
#define IBATINPUT_H

enum keyState
{
    kInvalid = 0x0,
    kDown = 0x1,
    kPress = 0x2,
    kDownPress = 0x3,
    kRelease = 0x4,
};

typedef std::map<u32,keyState> KeyMap;
typedef std::pair<u32,keyState> KeyPair;
//Push input states to have sections of buttons
class InputState
{
public:
    void UpdateKey(u32 key, keyState action)
    {
        m_KeyMap[key] = action;
    }
    void AddKey(u32 key)
    {
        KeyPair keyPair(key,kInvalid);
        m_KeyMap.insert(keyPair);
    }
    u32 GetKeyState(u32 key)
    {
        KeyMap::iterator iter = m_KeyMap.find(key);
        if(iter != m_KeyMap.end())
        {
            return iter->second;
        }
        else
        {
            return kInvalid;
        }
    }
    KeyMap m_KeyMap;
};

class IBatInput
{
    public:
        IBatInput();
        virtual ~IBatInput();

        virtual void UpdateButtons() = 0;

        virtual bool Initialize(GLFWwindow* _win) = 0;
        virtual void SetInputState(InputState* state) = 0;

        virtual bool GetButton(u32 key) = 0;
        virtual bool GetButtonDown(u32 key) = 0;
        virtual bool GetButtonUp(u32 key) = 0;

        //virtual bool GetKey(s32 kycode) = 0;
        //virtual bool GetKeyDown(s32 keycode) = 0;
        //virtual bool GetKeyUp(s32 keycode) = 0;
        //virtual s32 GetKeyState(s32 keycode) = 0;
    protected:
    private:
};
#endif // IBATINPUT_H
