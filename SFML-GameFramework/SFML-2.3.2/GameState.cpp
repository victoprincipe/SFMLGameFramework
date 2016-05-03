#include "GameState.h"

void GameState::init() {
	scene_->start();
}

void GameState::clean_up() {
	scene_ = NULL;
	event_handler_ = NULL;
}

void GameState::HandleEvents(GameEngine * game)
{
	event_handler_->handlerEvent(game);
}

void GameState::Draw(GameEngine * game)
{
	scene_->render(game);
}

void GameState::update(GameEngine * game) 
{
	scene_->update(game);
}
