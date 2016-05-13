#include "SpriteComponent.h"

void SpriteComponent::setSprite(sf::String path)
{
	this->texture.loadFromFile(path);
	this->sprite.setTexture(this->texture);
}

void SpriteComponent::Start(GameEngine *game)
{
	
}

void SpriteComponent::Update(GameEngine *game)
{	
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	this->sprite.setPosition(transform->getPosition());
	game->get_window_()->draw(this->sprite);
}

void SpriteComponent::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

float SpriteComponent::getPositionX()
{
	return this->sprite.getPosition().x;
}

float SpriteComponent::getPositionY()
{
	return this->sprite.getPosition().y;
}