#pragma once
#include "TransformComponent.h"
#include "GameObject.h"
#include "Component.h"

class MoverInimigo : public Component
{
public:
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

