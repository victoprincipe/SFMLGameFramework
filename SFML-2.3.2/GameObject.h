#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Component.h"
#include "SpriteComponent.h"

class Component;
class GameScene;

class GameObject
{	
private:
	sf::String name;	
	std::vector<Component*> components;		
public:	
	GameScene *gameScene = NULL;
	template <class CompType>
	void AddComponent(CompType *comp) {
		comp->setGameObject(this);
		components.push_back(comp);
	}	
	template <class CompType>
	CompType GetComponent() {
		for (std::vector<Component *>::iterator it = components.begin(); it != components.end(); ++it) {
			CompType comp = dynamic_cast<CompType>(*it);
			if (comp) {				
				return comp;
			}
		}
		return NULL; 
	}
	void setGameScene(GameScene *gameScene);
	GameObject *findGameObjectByName(sf::String name);
	std::vector<GameObject*> getSceneObjects();
	void Start(GameEngine *game);
	void Update(GameEngine *game);
	bool isSceneNull();
};

