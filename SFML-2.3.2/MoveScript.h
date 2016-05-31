#pragma once
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "GameObject.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "BulletScript.h"
#include "RigidbodyComponent.h"
#include "MoverCano.h"
#include "TextComponent.h"
#include "Pontuacao.h"

class MoveScript :	public Component
{
private:
	sf::Clock clock;
	sf::Time time;		
	Pontuacao* pontuacao_;
public:	
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

