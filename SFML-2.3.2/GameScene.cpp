#include "GameScene.h"

void GameScene::addGameObject(GameObject * go)
{
	go->setGameScene(this);
	TransformComponent *t = go->GetComponent<TransformComponent*>();
	if (t == NULL)
	{
		TransformComponent *t = new TransformComponent();
		go->AddComponent(t);
	}
	this->gameObjects.push_back(go);	
}

void GameScene::Start(GameEngine *game)
{	
	int size = this->gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		this->gameObjects[i]->Start(game);
	}		
}

void GameScene::Update(GameEngine *game)
{	
	int size = this->gameObjects.size();
	for (int i = 0; i < size; i++)
	{		
		if (this->gameObjects[i]->isEnable())
		{
			this->gameObjects[i]->Update(game);
		}						
	}
}