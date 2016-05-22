#pragma once
#include "TransformComponent.h"
#include "GameObject.h"
#include "Component.h"

class MoverCano : public Component
{
public:
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

