#include "MoveScript.h"

void MoveScript::Start(GameEngine *game)
{	
}

void MoveScript::Update(GameEngine *game)
{		
	this->time = clock.getElapsedTime();	
	if (this->time.asSeconds() >= 3)
	{		
		GameObject *marioTube = new GameObject();
		SpriteComponent *marioTubeSprite = new SpriteComponent();
		TransformComponent *transformTube = new TransformComponent();
		ColliderComponent *colliderTube = new ColliderComponent();
		MoverCano *mc = new MoverCano();	
		marioTube->setName("enemy");
		marioTubeSprite->setSprite("enemy.png");
		transformTube->setPosition(800, 100);
		marioTube->AddComponent(transformTube);
		marioTube->AddComponent(mc);
		marioTube->AddComponent(marioTubeSprite);	
		marioTube->AddComponent(colliderTube);
		this->gameObject->Instatiate(marioTube);
		this->clock.restart();
	}	
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		transform->move(0, -10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		transform->move(0, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{		
		GameObject *bullet = new GameObject();
		SpriteComponent *bulletSprite = new SpriteComponent();
		TransformComponent *bulletTransform = new TransformComponent();	
		ColliderComponent *bulletCollider = new ColliderComponent();
		BulletScript *bs = new BulletScript();

		

		bulletSprite->setSprite("bullet.png");
		bulletTransform->setPosition(transform->getPosition().x + 128, transform->getPosition().y + 33);		
		bullet->AddComponent(bulletSprite);		
		bullet->AddComponent(bulletTransform);
		bullet->AddComponent(bulletCollider);
		bullet->AddComponent(bs);		
		this->gameObject->Instatiate(bullet);
	}
}