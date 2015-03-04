#ifndef APPLICATION_H
#define APPLICATION_H

// File:application.h
// Description: This is an application file, the head of the snake
// Copywrite: Nathan Boyes - 01/03/2015



class Application
{
    public:
        Application();
        virtual ~Application();

        void Initialize(HINSTANCE hInst,const char* name, int width, int height);
        void Update();
        void Terminate();

        void EnableOpenGL();
        void DisableOpenGL();
    protected:
        HWND m_hWnd;
        HDC m_hDC;
        HGLRC m_hRC;
        u32 m_Width;
        u32 m_Height;

    private:
};

#endif // APPLICATION_H
