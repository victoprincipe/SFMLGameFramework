#include "EventHandler.h"
#include "IntroState.h"
#include "IntroScene.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::handlerEvent(GameEngine* game)
{
	// captura o evento
	game->get_window_()->pollEvent(event_);

	// realiza um comando dado o tipo de evento
	switch (event_.type) {
	case sf::Event::Closed:
		game->get_window_()->close();
		break;
	case sf::Event::KeyPressed:
		if (event_.key.code == sf::Keyboard::Space) {
			AbstractScene* intro_scene = new IntroScene();
			game->change_state(IntroState::Instance(intro_scene, this));
		}
		if (event_.key.code == sf::Keyboard::BackSpace) {
			AbstractScene* mario_scene = new Scene();
			game->change_state(IntroState::Instance(mario_scene, this));
		}
	}
}
