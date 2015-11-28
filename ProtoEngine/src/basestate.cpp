#include "ProtoEngine/basestate.h"

BaseState::BaseState(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,GameContext& gc)
	: mGameContext(gc), m_GraphicsSystem(graphicsSystem),m_InputSystem(inputSystem)
{
}

BaseState::~BaseState()
{
}
