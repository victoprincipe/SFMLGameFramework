#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::start()
{
	this->texture.loadFromFile("mario.png");
	this->sprite.setTexture(this->texture);	
	this->sprite.setPosition(200, 200);	
}

void Scene::update()
{			
	
		if (this->game->event.type == sf::Event::Closed)
		{
			this->game->window->close();
		}		
		if (this->game->event.type == sf::Event::KeyPressed)
		{
			if (this->game->event.key.code == sf::Keyboard::Z)
			{
				this->sprite.setRotation(this->sprite.getRotation() + 1);
			}
		}	
}

void Scene::render()
{
	this->game->window->draw(this->sprite);
}