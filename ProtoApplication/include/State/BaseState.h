#ifndef INCLUDED_BASE_STATE
#define INCLUDED_BASE_STATE

//File: basestate.h
//Description: Base game state, derive from this to make new game states.
//Copywrite: Nathan Boyes - 08/03/2015

#include "GameContext.h"
#include "GameStates.h"

class BaseState
{
public:
	BaseState(GameContext& gc);
	virtual ~BaseState();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual int Update(float deltaTime) = 0;
	virtual void Render() = 0;

protected:
	GameContext& mGameContext;
};

#endif
