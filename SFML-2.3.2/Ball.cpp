#include "Ball.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>

# define M_PI           3.14159265358979323846

Ball::Ball(vector<Ball*> balls)
{
	balls_ = balls;
	ball_shape_.setFillColor(sf::Color::White);
}

sf::CircleShape Ball::getShape()
{
	return ball_shape_;
}

void Ball::set_position(float x, float y)
{
	position_ = sf::Vector2f{ x, y };
}

void Ball::set_mass(float mass)
{
	mass_ = mass;
}

void Ball::setup_objects()
{	
	//	position_ = sf::Vector2f{ random_->rand_f(50) , random_->rand_f(50) };
//	angle_ = (rand() % 360 + 1.0f) / 360.f * M_PI * 2;
	linearVelocity_ = sf::Vector2f{ 0, 0 };
	angularVelocity_ = 0;	
	//mass_ = random_->rand_i(20) + 50;
	ball_shape_.setPosition(position_.x, position_.y);
	ball_shape_.setRadius(mass_);
}

void Ball::apply_forces()
{
	sf::Vector2f f = { 0, 100 };
	force_ = f;
	// r is the 'arm vector' that goes from the center of mass to the point of force application
	sf::Vector2f r = { mass_ / 2, mass_ / 2 };
	torque_ = r.x * f.y - r.y * f.x;
}

void Ball::update_position()
{
	position_.x += linearVelocity_.x;
	position_.y += linearVelocity_.y;
	ball_shape_.setPosition(position_.x, position_.y);	
}

void Ball::update_velocities()
{	
	sf::Vector2f linearAcceleration = sf::Vector2f{ force_.x / mass_, force_.y / mass_ };
	linearVelocity_.x = linearAcceleration.x;
	linearVelocity_.y = linearAcceleration.y;
}

void Ball::detect_collisions()
{

}

void Ball::solve_constrains()
{
}

void Ball::draw(GameEngine * game)
{
	game->get_window_()->draw(ball_shape_);
}

Ball::~Ball()
{
}
