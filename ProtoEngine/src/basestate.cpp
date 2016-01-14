#include "ProtoEngine/basestate.h"

BaseState::BaseState(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc)
	: m_GraphicsSystem(graphicsSystem),m_InputSystem(inputSystem),m_ResourceData(resSystem), mGameContext(gc)
{
}

BaseState::~BaseState()
{
}
