#include "GameScene.h"

void GameScene::addGameObject(GameObject * go)
{
	go->setGameScene(this);
	this->gameObjects.push_back(go);
}

void GameScene::Start(GameEngine *game)
{
	for (std::vector<GameObject*>::iterator it = this->gameObjects.begin(); it != this->gameObjects.end(); it++)
	{
		(*it)->Start(game);
	}
}

void GameScene::Update(GameEngine *game)
{
	for (std::vector<GameObject*>::iterator it = this->gameObjects.begin(); it != this->gameObjects.end(); it++)
	{
		(*it)->Update(game);
	}
}