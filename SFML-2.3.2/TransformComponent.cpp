#include "TransformComponent.h"

void TransformComponent::setPosition(float x, float y)
{
	this->transform.setPosition(x, y);
}

void TransformComponent::setScale(float x, float y)
{
	this->transform.setScale(x, y);
}

sf::Vector2f TransformComponent::getScale()
{
	return this->transform.getScale();
}

sf::Vector2f TransformComponent::getPosition()
{
	return this->transform.getPosition();
}

void TransformComponent::move(float x, float y)
{
	this->transform.move(x, y);
}

void TransformComponent::Start(GameEngine *game)
{

}

void TransformComponent::Update(GameEngine *game)
{

}
