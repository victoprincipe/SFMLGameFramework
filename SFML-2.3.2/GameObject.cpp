#include "GameObject.h"

void GameObject::setName(sf::String name)
{
	this->name = name;
}

sf::String GameObject::getName()
{
	return this->name;
}

GameObject * GameObject::findGameObjectByName(sf::String name)
{
	return NULL;
}

void GameObject::Instatiate(GameObject *go)
{
	this->gameScene->addGameObject(go);
}

void GameObject::Destroy(GameObject *go)
{	
	this->size = this->gameScene->gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		if (this->gameScene->gameObjects[i] == go)
		{			
			this->gameScene->gameObjects.erase(this->gameScene->gameObjects.begin() + i);			
		}
	}		
}

bool GameObject::isEnable()
{
	return this->enable;
}

void GameObject::setEnable(bool enable)
{
	this->enable = enable;
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

void GameObject::freeGameObjects()
{
	this->gameScene->gameObjects.shrink_to_fit();
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

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}