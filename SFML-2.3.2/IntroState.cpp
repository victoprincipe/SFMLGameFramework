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
		case sf::Event::KeyPressed:
			game->change_scene(1);
			break;
	}
	
}

void IntroState::update(GameEngine* game)
{	
	this->sprite_.setPosition(this->sprite_.getPosition().x + 1, this->sprite_.getPosition().y);	
}

void IntroState::Draw(GameEngine* game)
{	
	game->get_window_()->draw(this->sprite_);		
}

IntroState* IntroState::intro_state_ = NULL;

IntroState* IntroState::Instance()
{
	if (intro_state_ == NULL)
		intro_state_ = new IntroState();
		intro_state_->init();
	return intro_state_;
}
