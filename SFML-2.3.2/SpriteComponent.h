#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "TransformComponent.h"

class GameObject;

class SpriteComponent : public Component
{
private:
	sf::Sprite sprite;
	sf::Texture texture;	
public:		
	void setSprite(sf::String path);
	void setPosition(float x, float y);
	float getPositionX();
	float getPositionY();
	float getSpriteWidth();
	float getSpriteHeight();
	sf::FloatRect getRect();
	void Start(GameEngine *game);
	void Update(GameEngine *game);
};

