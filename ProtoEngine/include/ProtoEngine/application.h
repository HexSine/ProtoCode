#ifndef APPLICATION_H
#define APPLICATION_H

// File:application.h
// Description: This is an application file, the head of the snake
// Copywrite: Nathan Boyes - 01/03/2015

//Undefined, required Functions


class Application
{
    public:
        Application();
        virtual ~Application();

        bool Initialize(HINSTANCE hInst,const char* name, int width, int height);
        void Update();
        void Terminate();

        GLFWwindow* GetWin(){return p_window;}
    protected:

        virtual bool OnInitialize(){return true;};
        virtual void OnUpdate(){};
        virtual void OnTerminate(){};

        GLFWwindow* p_window;
        u32 m_Width;
        u32 m_Height;
        double m_prevTime;
    private:
};
namespace Proto
{
extern bool ProtoInitialize();
    extern bool ProtoUpdate(const long double deltaTime);
    extern void ProtoTerminate();
    extern void ProtoRender();
}
#endif // APPLICATION_H
