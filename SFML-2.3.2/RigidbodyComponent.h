#pragma once
#include <vector>
#include "GameScene.h"
#include "Component.h"
#include "ColliderComponent.h"

class GameScene;

class RigidbodyComponent :	public Component
{
	friend class GameScene;
private:	
	float velocityX;
	float velocityY;
	float gravity;	
	void overlap();
public:
	void isKinematic(bool isKinematic);
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

