#include "IntroScene.h"

void IntroScene::start()
{
	if (!texture_.loadFromFile("game_of_hyrule.jpg")) {
		printf("game_of_hyrule.jpg not found!");
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(20, 20);
}

void IntroScene::update(GameEngine* game)
{
}

void IntroScene::render(GameEngine* game)
{
	game->get_window_()->draw(sprite_);
}
