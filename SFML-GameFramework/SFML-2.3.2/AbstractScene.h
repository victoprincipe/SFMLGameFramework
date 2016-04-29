#pragma once
#include "Game.h"

class Game;

class AbstractScene
{
protected:
	Game *game;
public:
	void setGame(Game *game);
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

