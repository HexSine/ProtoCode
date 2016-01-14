//Include Headers


#include "BatApplication/precompiled.h"
#include "ProtoEngine/ProtoEngine.h"

#include "BatApplication/frontend.h"
#include "BatApplication/gameplay.h"
/*#include "State/BaseState.h"
#include "State/FrontEnd.h"
#include "State/GamePlay.h"
#include "State/GameContext.h"
#include "State/GameStates.h"*/

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

Application app;
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
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
    ResourceManager resSystem;
    GraphicsSystem gSys;
    InputSystem input;
    int nextState = 0;
    bool ProtoInitialize()
    {
        input.Initialize(app.GetWin());
        gSys.Initialize(&resSystem);
        currentState = new FrontEnd(gSys,input,resSystem,gameContext);
        currentState->Load();

        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        return true;
    }
    bool ProtoUpdate(const long double deltaTime)
    {
        input.UpdateButtons();
        //check if we need to change state
        if(nextState != 0)
        {
            //leave the current state
            if(currentState != NULL)
            {
                currentState->Unload();
                delete currentState;
            }
            switch(nextState)
            {
            case 1:
                currentState = new FrontEnd(gSys,input,resSystem,gameContext);
                break;
            case 2:
                currentState = new Gameplay(gSys,input,resSystem,gameContext);
                break;
            }
            if(currentState != NULL)
            {
                currentState->Load();
            }
        }
        nextState = currentState->Update(deltaTime);
        return (nextState == 2);
        return false;
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
