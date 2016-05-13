#include "MoveScript.h"

void MoveScript::Start(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	transform->setPosition(200, 200);
}

void MoveScript::Update(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{		
		transform->move(-1 * game->getDeltaTime(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		transform->move(1 * game->getDeltaTime(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{		
		game->change_scene(1);
	}
}