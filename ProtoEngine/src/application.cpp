#include "../precompiled.h"
#include "ProtoEngine/application.h"

namespace
{
    LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch(uMsg)
        {

		case WM_DESTROY:
			{
				PostQuitMessage(0);
			}
        default:
            return DefWindowProc(hWnd,uMsg,wParam,lParam);
        }
        return 0;
    }
}

Application::Application()
{

}

Application::~Application()
{
    //dtor
}

void Application::EnableOpenGL()
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    m_hDC = GetDC(m_hWnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(m_hDC, &pfd);

    SetPixelFormat(m_hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    m_hRC = wglCreateContext(m_hDC);

    wglMakeCurrent(m_hDC, m_hRC);
}
void Application::DisableOpenGL ()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(m_hRC);
    ReleaseDC(m_hWnd, m_hDC);
}

void Application::Initialize(HINSTANCE hInstance,const char* name,int width, int height)
{
    //Create Window Class
    WNDCLASSEX wcex;
    wcex.lpfnWndProc = WinProc;
    wcex.lpszClassName = name;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    RegisterClassEx(&wcex);
    //Create Window
    m_hWnd = CreateWindowEx(0,name,name,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,height,width,NULL,NULL,hInstance,NULL);

    ShowWindow(m_hWnd,SW_SHOW);


    /* enable OpenGL for the window */
    EnableOpenGL();

}
void Application::Update()
{
    MSG msg;
    bool quit;
    while(quit == false)
    {
        PeekMessage(&msg,NULL,0,0,PM_REMOVE);
        if(msg.message == WM_QUIT)
        {
            quit = true;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}
void Application::Terminate()
{

    DisableOpenGL();

    DestroyWindow(m_hWnd);
}
