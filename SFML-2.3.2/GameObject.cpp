#include "GameObject.h"

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