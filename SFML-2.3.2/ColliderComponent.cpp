#include "ColliderComponent.h"

void ColliderComponent::setX(float x)
{
	this->x = x;
}

void ColliderComponent::setY(float y)
{
	this->y = y;
}

void ColliderComponent::setWidth(float width)
{
	this->width = width;
}

void ColliderComponent::setHeight(float height)
{
	this->height = height;
}

float ColliderComponent::getX()
{
	return this->x;
}

float ColliderComponent::getY()
{
	return this->y;
}

float ColliderComponent::getWidth()
{
	return this->width;
}

float ColliderComponent::getHeight()
{
	return this->height;
}

void ColliderComponent::Start(GameEngine *game)
{
	SpriteComponent *sprite = this->gameObject->GetComponent<SpriteComponent*>();
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	this->x = transform->getPosition().x;
	this->y = transform->getPosition().y;
	this->width = sprite->getSpriteWidth();
	this->height = sprite->getSpriteHeight();	
}

void ColliderComponent::Update(GameEngine *game)
{
	SpriteComponent *sprite = this->gameObject->GetComponent<SpriteComponent*>();
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	this->x = transform->getPosition().x;
	this->y = transform->getPosition().y;
	this->width = sprite->getSpriteWidth();
	this->height = sprite->getSpriteHeight();
}

bool ColliderComponent::isKinematic()
{
	return this->kinematic;
}

void ColliderComponent::setKinematic(bool kinematic)
{
	this->kinematic = kinematic;
}

ColliderComponent::ColliderComponent()
{
}


ColliderComponent::~ColliderComponent()
{
}
