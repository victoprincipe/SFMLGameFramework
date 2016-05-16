#include "GameObject.h"

GameObject * GameObject::findGameObjectByName(sf::String name)
{
	return NULL;
}

bool GameObject::isSceneNull()
{
	if (this->gameScene == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::vector<GameObject*> GameObject::getSceneObjects()
{
	return this->gameScene->gameObjects;
}

void GameObject::Start(GameEngine *game)
{
	for (std::vector<Component*>::iterator it = this->components.begin(); it != this->components.end(); it++)
	{
		(*it)->Start(game);
	}
}

void GameObject::Update(GameEngine *game)
{
	for (std::vector<Component*>::iterator it = this->components.begin(); it != this->components.end(); it++)
	{
		(*it)->Update(game);
	}
}

void GameObject::setGameScene(GameScene *scene)
{
	this->gameScene = scene;
}

