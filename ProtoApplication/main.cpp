

#define GLEW_STATIC

//Include Headers


#include <windows.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/wglew.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>

#include "ProtoEngine.h"
#include "ProtoEngine/proto_core.h"
#include "ProtoEngine/application.h"

#include "State/BaseState.h"
#include "State/FrontEnd.h"
#include "State/GamePlay.h"
#include "State/GameContext.h"
#include "State/GameStates.h"

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
    BaseState* currentState;
    GameContext gameContext;
    int nextState = GameState::Invalid;
    bool ProtoInitialize()
    {
        currentState = new FrontEnd(gameContext);
        currentState->Load();

        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }
    bool ProtoUpdate(const long double deltaTime)
    {
        //check if we need to change state
        if(nextState != GameState::Invalid)
        {
            //leave the current state
            if(currentState != NULL)
            {
                currentState->Unload();
                delete currentState;
            }
            switch(nextState)
            {
            case GameState::Frontend:
                currentState = new FrontEnd(gameContext);
                break;
            case GameState::Gameplay:
                currentState = new GamePlay(gameContext);
                break;
            }
            if(currentState != NULL)
            {
                currentState->Load();
            }
        }
        nextState = currentState->Update(deltaTime);
        return (nextState == GameState::Quit);
        return true;
    }


    void ProtoTerminate()
    {
        currentState->Unload();
        delete currentState;
        currentState = NULL;
    }

    void ProtoRender()
    {
        currentState->Render();
    }



}
