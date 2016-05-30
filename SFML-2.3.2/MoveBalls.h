#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "GameScene.h"
#include "GameObject.h"
#include "Ball.h"
#include "RigidBodyDynamicComponent.h"
#include "Component.h"
#include "RandomGenerator.h"

class Ball;
class RandomGenerator;

class MoveBalls	: public Component
{
public:
	MoveBalls(GameScene *scene, int num_balls);	
	MoveBalls(GameObject *balls, int num_balls);
	~MoveBalls();
	void Start(GameEngine * game) override;
	void Update(GameEngine * game) override;
private:
	void init();
	std::vector<Ball*> rigidBodies;
	GameScene* scene_;
	GameObject * balls_;
	int num_balls_;	
};

