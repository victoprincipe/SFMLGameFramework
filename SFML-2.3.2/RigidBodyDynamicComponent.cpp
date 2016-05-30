#include "RigidBodyDynamicComponent.h"


void RigidBodyDynamicComponent::Start(GameEngine * game)
{
	setup_objects();
}

void RigidBodyDynamicComponent::Update(GameEngine * game)
{
	apply_forces();
	update_position();
	update_velocities();
	detect_collisions();
	solve_constrains();
	draw(game);
}
