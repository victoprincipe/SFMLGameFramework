#include "Input.h"

void Input::eventHandling(GameEngine *game)
{
	sf::Event event;
	// captura o evento
	game->get_window_()->pollEvent(event);
	
	
}

Input::Input()
{
}


Input::~Input()
{
}
