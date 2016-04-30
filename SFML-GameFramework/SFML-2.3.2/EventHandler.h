#pragma once
#include "Game.h"
class Game;

/* Trata todos os eventos gerados no jogo.*/
class EventHandler {
private:	
public:
	EventHandler();
	~EventHandler();
	void handlerEvent(sf::Event event, Game* game);

};