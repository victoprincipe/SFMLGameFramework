#pragma once
#include "GameObject.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "MoverCano.h"
#include "BulletScript.h"
#include "SoundComponent.h"//som

class MoveScript :	public Component
{	
private:
	sf::Clock clock;
	sf::Time time;
	int score;
	std::string toString(int data_int);
public:
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

