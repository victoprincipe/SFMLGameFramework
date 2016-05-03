#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Game;

class Input
{
private:
	Game *game;
public:
	void setGame(Game *game);
	Input();
	~Input();
};

