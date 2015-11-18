#include "State/FrontEnd.h"
#include "ProtoEngine/Input/input.h"
FrontEnd::FrontEnd(GameContext& gc)
	: BaseState(gc), quad(1,1)
{
}
FrontEnd::~FrontEnd()
{
}

void FrontEnd::Load()
{

    StartMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/FrontEnd/start.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize
    StartMaterial.m_ProgramID = GraphicsSystem::LoadProgram("./TexturedVertexShader.glsl","./TexturedFragmentShader.glsl");

    BackGroundMaterial.m_TextureID = SOIL_load_OGL_texture("./Data/Textures/FrontEnd/BackGround.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//Magnify
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//Minimize

    //TODO Fix startmaterial assignment
    BackGroundMaterial.m_ProgramID = StartMaterial.m_ProgramID;

    background.m_Renderable.p_Material = &BackGroundMaterial;
    background.Init();


    start.m_Renderable.p_Material = &StartMaterial;
    start.Init();


    cam.SetView(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
    cam.SetOrtho(glm::vec3(0,0,0),640,480,0.1f,100.0f);
    m_GraphicsSys.SetProgram(StartMaterial.m_ProgramID);

}
void FrontEnd::Unload()
{
    glDeleteTextures(1,&StartMaterial.m_TextureID);
    glDeleteTextures(1,&BackGroundMaterial.m_TextureID);
    glDeleteProgram(StartMaterial.m_ProgramID);

    start.Terminate();
}
int FrontEnd::Update(float deltaTime)
{
	int nextState = GameState::Invalid;
	start.Update(deltaTime);
	if(Input::GetKeyDown(GLFW_KEY_ENTER))
    {
        nextState = GameState::Gameplay;
    }
	return nextState;
}
void FrontEnd::Render()
{
    //ship.m_Renderable.Render(&cam);
    //TODO Fix order
    m_MatStack.PushMatrix(cam.m_Projection);
    m_MatStack.PushMatrix(cam.m_View);

    m_MatStack.PushMatrix(start.m_Transform.m_transform);
    m_GraphicsSys.DrawRenderObject(start.m_Renderable,m_MatStack.GetMatrix());
    m_MatStack.PopMatrix();

    m_MatStack.PushMatrix(background.m_Transform.m_transform);
    m_GraphicsSys.DrawRenderObject(background.m_Renderable,m_MatStack.GetMatrix());
    m_MatStack.PopMatrix();

    m_MatStack.Clear();
}
