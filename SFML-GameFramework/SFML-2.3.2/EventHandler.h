#pragma once
#include "GameEngine.h"
class GameEngine;

/* Trata todos os eventos gerados no jogo.*/
class EventHandler {
public:
	EventHandler();
	~EventHandler();
	virtual void handlerEvent(GameEngine* game);
	inline sf::Event get_event_() { return event_; }
protected:
	sf::Event event_;
};