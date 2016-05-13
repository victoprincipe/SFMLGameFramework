#pragma once
#include "GameEngine.h"

class GameEngine;
class GameObject;

class GameScene {
private:
	std::vector<GameObject*> gameObjects;
public:	
	void Start(GameEngine* game);
	void Update(GameEngine* game);
	void addGameObject(GameObject * go);
public:
	GameScene() {};
	~GameScene() {};	
};
