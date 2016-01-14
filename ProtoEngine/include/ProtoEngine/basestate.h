#ifndef INCLUDED_BASE_STATE
#define INCLUDED_BASE_STATE

//File: basestate.h
//Description: Base game state, derive from this to make new game states.
//Copywrite: Nathan Boyes - 08/03/2015

#include "ProtoEngine\gamecontext.h"

class BaseState
{
public:
	BaseState(IBatGraphicsSystem& graphicsSystem,IBatInput& inputSystem,ResourceManager& resSystem,GameContext& gc);
	virtual ~BaseState();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual int Update(float deltaTime) = 0;
	virtual void Render() = 0;

	std::vector<Entity> mEntities;

protected:
    IBatGraphicsSystem& m_GraphicsSystem;
    IBatInput& m_InputSystem;
    ResourceManager& m_ResourceData;
	GameContext& mGameContext;
};

#endif
