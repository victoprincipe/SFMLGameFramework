#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

class MoveScript :	public Component
{
private:
	
public:
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

