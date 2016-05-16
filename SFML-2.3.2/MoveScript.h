#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "CameraComponent.h"

class MoveScript :	public Component
{
private:
	
public:
	void Start(GameEngine *game) override;
	void Update(GameEngine *game) override;
};

