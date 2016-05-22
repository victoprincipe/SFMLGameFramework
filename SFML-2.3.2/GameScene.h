#pragma once
#include "GameEngine.h"
#include "GameObject.h"
#include <iostream>
#include <algorithm>

class GameEngine;
class GameObject;

class GameScene {
	friend class GameObject;
private:	
public:	
	std::vector<GameObject*> gameObjects;	
	void Start(GameEngine* game);
	void Update(GameEngine* game);
	void addGameObject(GameObject *go);
public:
	GameScene() {};
	~GameScene() {};	
};
