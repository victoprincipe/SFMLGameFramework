#include "IntroState.h"

void IntroState::init()
{	
	if (!render_texture_.create(500, 500)) {
		printf("Render Texture not created");
	}
	if (!texture_.loadFromFile("mario.png")) {
		printf("Error in load file mario.png");
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(200, 200);

	printf("IntroState Init\n");
}

void IntroState::clean_up() 
{
	printf("IntroState Cleanup\n");
}

void IntroState::pause() 
{
	printf("IntroState pause\n");
}

void IntroState::resume() 
{
	printf("IntroState resume\n");
}

void IntroState::HandleEvents(GameEngine* game) 
{
	sf::Event event;

	// captura o evento
	game->get_window_()->pollEvent(event);

	// realiza um comando dado o tipo de eventp
	switch (event.type) {
		case sf::Event::Closed:
			game->get_window_()->close();
			break;			
	}
	
}

void IntroState::update(GameEngine* game)
{	
	game->get_window_()->clear();
}

void IntroState::Draw(GameEngine* game)
{	
	render_texture_.clear(sf::Color::Cyan);
	render_texture_.draw(sprite_);
	render_texture_.display();
	game->get_window_()->clear();

	sf::Sprite sprite(render_texture_.getTexture());
	game->get_window_()->draw(sprite);
	game->get_window_()->display();
}

IntroState* IntroState::intro_state_ = NULL;

IntroState* IntroState::Instance()
{
	if (intro_state_ == NULL)
		intro_state_ = new IntroState();
	return intro_state_;
}
