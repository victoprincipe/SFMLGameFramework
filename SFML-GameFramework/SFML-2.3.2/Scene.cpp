#include "Scene.h"



Scene::Scene(sf::RenderWindow *window)
{
	this->window = window;
}

void Scene::start()
{
	this->marioTexture->loadFromFile("mario.png");
	this->mario->setTexture(*this->marioTexture);
	this->mario->setPosition(200, 200);
}

void Scene::update()
{
	
}

void Scene::render()
{
	this->window->draw(*this->mario);
}

Scene::~Scene()
{
}
