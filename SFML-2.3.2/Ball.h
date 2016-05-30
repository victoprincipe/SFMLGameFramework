#pragma once
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include "RigidBodyDynamicComponent.h"
#include "RandomGenerator.h"
#include "GameEngine.h"

using namespace std;

class Ball : public
	RigidBodyDynamicComponent
{
public:
	Ball(vector<Ball*> balls);
	sf::CircleShape getShape();
	void set_position(float x, float y);
	void set_mass(float mass);
	~Ball();
protected:
	virtual void setup_objects() override;
	virtual void apply_forces() override;
	virtual void update_position() override;
	virtual void update_velocities() override;
	virtual void detect_collisions() override;
	virtual void solve_constrains() override;
	virtual void draw(GameEngine *game) override;
private:	
	sf::CircleShape ball_shape_;
	vector<Ball*> balls_;
	sf::Vector2f position_;
	sf::Vector2f linearVelocity_;
	float angle_;
	float angularVelocity_;
	sf::Vector2f force_;
	float torque_;
	float mass_;
};