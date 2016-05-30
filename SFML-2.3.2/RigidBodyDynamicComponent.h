#pragma once
#include "Component.h"
class RigidBodyDynamicComponent :
	public Component
{
public:	
	RigidBodyDynamicComponent() {};	
	void Start(GameEngine * game) override;
	void Update(GameEngine * game) override;
protected:
	virtual void setup_objects() = 0;
	virtual void apply_forces() = 0;
	virtual void update_position() = 0;
	virtual void update_velocities() = 0;
	virtual void detect_collisions() = 0;
	virtual void solve_constrains() = 0;
	virtual void draw(GameEngine *game) = 0;
};