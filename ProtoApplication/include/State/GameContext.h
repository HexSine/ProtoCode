#ifndef INCLUDED_GAME_CONTEXT
#define INCLUDED_GAME_CONTEXT

// File: gamecontext.h
// Description: Keeps information from different sections of the game
// Copywrite: Nathan Boyes - 09/03/2015
#include "ProtoEngine/ProtoEngine.h"

class GameContext
{
public:
	GameContext();
	virtual ~GameContext();

	virtual void SaveData(const char* pFileName){};
	virtual void LoadData(const char* pFileName){};

	virtual int GetLevel() const	{return m_Level;}
	virtual void SetLevel(int lvl)	{m_Level = lvl;}

private:
	int m_Level;
};
#endif
