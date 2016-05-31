#pragma once
#include <vector>
#include "GameScene.h"
#include "Component.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"

class GameScene;

class RigidbodyComponent :	public Component
{
	friend class GameScene;
private:	
	float velocityX;
	float velocityY;
	float accelX;
	float accelY;
	float friction;
	float gravity;	
	void overlap();	
public:
	void isKinematic(bool isKinematic);
	void setAccelX(float accelX);
	float getAccelX();
	void setAccelY(float accelY);
	float getAccelY();
	void setVelocityX(float velocityX);
	float getVelocityX();
	void setVelocityY(float velocityY);
	float getVelocityY();
	void setGravity(float gravity);
	float getGravity();

	void Update(GameEngine *game);
	void Start(GameEngine *game);
	RigidbodyComponent();
	~RigidbodyComponent();
};

