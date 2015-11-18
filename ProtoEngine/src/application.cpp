#include "ProtoEngine/precompiled.h"
#include "ProtoEngine/application.h"
Application::Application() : p_window(NULL)
{

}

Application::~Application()
{
    //dtor
}
bool Application::Initialize(HINSTANCE hInstance,const char* name,int width, int height)
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MaxOS happy;
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    p_window = glfwCreateWindow(width,height,name,NULL,NULL);
    if( p_window == NULL )
    {
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(p_window);
    glewExperimental=true; // Needed in core profile

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return false;
    }

    glfwSetInputMode(p_window,GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.5f,0.0f,0.8f,1.0f);

    //Initialize Input Handling
    //Input::Init(p_window);

    bool ret = Proto::ProtoInitialize();
    return ret;
}
void Application::Update()
{
    m_prevTime = glfwGetTime();
    do{
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - m_prevTime;
        glfwSwapBuffers(p_window);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Proto::ProtoUpdate(deltaTime);
        Proto::ProtoRender();
        m_prevTime = currentTime;
    }
    while( glfwGetKey(p_window,GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(p_window) == 0);
}
void Application::Terminate()
{
   glfwTerminate();
   Proto::ProtoTerminate();
}
