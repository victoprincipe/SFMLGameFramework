#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"


class TransformComponent :	public Component
{
private:
	sf::Transformable transform;
	int z_order;
public:
	TransformComponent();
	void setZorder(int z);
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void move(float x, float y);
	int getZorder();	
	sf::Vector2f getPosition();
	sf::Vector2f getScale();
	void Start(GameEngine *game);
	void Update(GameEngine *game);
};