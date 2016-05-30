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
	bool enable = true;	
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
	void Instatiate(GameObject *go);
	void Destroy(GameObject *go);
	void Start(GameEngine *game);
	void Update(GameEngine *game);
	void setName(sf::String name);
	void setEnable(bool enable);
	bool isEnable();
	sf::String getName();	
	int getComponentsSize();
};

