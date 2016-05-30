#pragma once
#include <iostream>

class GameEngine;
class GameObject;

class Component
{
protected:
	
private:
	static int unique_id_generator;
	int unique_id;	
public:
	GameObject *gameObject;
	Component() {
		
	}

	int GetUniqueId() {
		return unique_id;
	}
	void setGameObject(GameObject *go);
	virtual void Start(GameEngine *game) = 0; 
	virtual void Update(GameEngine *game) = 0;	
};

