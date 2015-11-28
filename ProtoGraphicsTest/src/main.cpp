#include <stdio.h>
#include <iostream>

#include <windows.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/wglew.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include "ProtoEngine/protoengine.h"
#include "BatKernel/matrixstack.h"
#include "ProtoGraphicsLib/ProtoGraphicsLib.h"

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    Application app;
    if(app.Initialize(hInstance,"ProtoWindow",1280,960))
    {
        app.Update();
        app.Terminate();
    }
    return 0;
}
namespace Proto
{
    GraphicsSystem gSystem;
    ResourceManager<Mesh> meshLoader;
    ResourceManager<Shader> shaderLoader;
    ResourceManager<Texture> textureLoader;
    ResourceManager<Material> materialLoader;

    Camera cam;
    Material* mat;
    RenderObject renderObj;
    MatrixStack mStack;

    bool ProtoInitialize()
    {
        if(!gSystem.Initialize())
        {
            return false;
        }
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        std::string URIshader = shaderLoader.Load("./Data/Shaders/TexturedProgram.glsl");
        std::string URImesh = meshLoader.Load("./Data/Models/quad.obj");
        std::string URITex = textureLoader.Load("./Data/Textures/Map/block_tile.png");
        mat = new Material();
        mat->m_ProgramID = shaderLoader.Get(URIshader).m_ShaderID;
        mat->m_TextureID = textureLoader.Get(URITex).m_TextureID;
        renderObj.p_Mesh = meshLoader.GetPtr(URImesh);
        renderObj.p_Material = mat;

        cam.SetView(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
        cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);

        return true;
    }
    bool ProtoUpdate(const long double deltaTime)
    {
        //check if we need to change state
        return false;
    }
    void ProtoTerminate()
    {
        shaderLoader.UnloadAll();
        meshLoader.UnloadAll();
    }
    void ProtoRender()
    {
        mStack.PushMatrix(cam.m_Projection);
        mStack.PushMatrix(cam.m_View);
        gSystem.DrawRenderObject(renderObj,mStack.GetMatrix());
        mStack.PopMatrix();
        mStack.PopMatrix();
    }
}

