#include "Scene2.h"


void Scene2::init()
{
	if (!render_texture_.create(500, 500)) {
		printf("Render Texture not created");
	}
	if (!texture_.loadFromFile("gameMenu.png")) {
		printf("Error in load file mario.png");
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(0, 0);

}

void Scene2::clean_up()
{
	printf("IntroState Cleanup\n");
}

void Scene2::pause()
{
	printf("IntroState pause\n");
}

void Scene2::resume()
{
	printf("IntroState resume\n");
}

void Scene2::HandleEvents(GameEngine* game)
{
	sf::Event event;
	// captura o evento
	game->get_window_()->pollEvent(event);

	// realiza um comando dado o tipo de eventp
	switch (event.type) {
	case sf::Event::Closed:
		game->get_window_()->close();
		break;
	case sf::Event::KeyPressed:
		game->change_scene(0);
		break;
	}

}

void Scene2::update(GameEngine* game)
{
	//this->sprite_.setPosition(this->sprite_.getPosition().x + 1, this->sprite_.getPosition().y);
}

void Scene2::Draw(GameEngine* game)
{
	game->get_window_()->draw(this->sprite_);
}

Scene2* Scene2::scene_ = NULL;

Scene2* Scene2::Instance()
{
	if (scene_ == NULL)
		scene_ = new Scene2();
	scene_->init();
	return scene_;
}
