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
}

void Scene::update()
{

}

void Scene::render()
{
	this->game->window->draw(this->sprite);
}