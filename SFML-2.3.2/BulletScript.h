#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"

class BulletScript : public Component
{
public:
	void Start(GameEngine *game);
	void Update(GameEngine *game);
};

