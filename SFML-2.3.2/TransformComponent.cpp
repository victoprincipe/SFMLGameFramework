#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	this->setPosition(0,0);
	this->setScale(1, 1);
	this->setZorder(0);
}

void TransformComponent::setZorder(int z)
{
	this->z_order = z;
}

void TransformComponent::setPosition(float x, float y)
{
	this->transform.setPosition(x, y);
}

void TransformComponent::setScale(float x, float y)
{
	this->transform.setScale(x, y);
}

int TransformComponent::getZorder()
{
	return this->z_order;
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
