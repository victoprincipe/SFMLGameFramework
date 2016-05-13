#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "GameEngine.h"

class CameraComponent :	public Component
{
private:
	sf::View camera;
public:
	void setZoom(float zoom);
	void setRotation(float rotation);
	void rotateCamera(float rotation);
	void move(float x, float y);
	void Update(GameEngine *game);
	void Start(GameEngine *game);
};

