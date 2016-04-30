#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::handlerEvent(sf::Event event, Game* game)
{
	if (event.type == sf::Event::Closed)
	{
		game->window->close();
	}
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			if (game->gameState == Game::RUNNING)
				game->gameState = Game::PAUSED;
			else
				game->gameState = Game::RUNNING;
		}
	}
}
