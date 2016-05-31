#include "MoveScript.h"

/*
std::string to_string(int value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}*/

void MoveScript::Start(GameEngine *game)
{			
	pontuacao_ = new Pontuacao(this->gameObject->GetComponent<TextComponent*>());
}

void MoveScript::Update(GameEngine *game)
{		
	// atualizar o texto da pontuação		
	//this->gameObject->GetComponent<TextComponent*>()->set_string(std::string("SCORE: ") + to_string(score_));
	this->time = clock.getElapsedTime();	
	if (this->time.asSeconds() >= 3)
	{		
		GameObject *marioTube = new GameObject();
		SpriteComponent *marioTubeSprite = new SpriteComponent();
		TransformComponent *transformTube = new TransformComponent();
		ColliderComponent *colliderTube = new ColliderComponent();
		MoverInimigo *mc = new MoverInimigo();	
		marioTube->setName("enemy");
		marioTubeSprite->setSprite("enemy.png");
		transformTube->setPosition(900, rand() % 800);
		marioTube->AddComponent(transformTube);
		marioTube->AddComponent(mc);
		marioTube->AddComponent(marioTubeSprite);	
		marioTube->AddComponent(colliderTube);
		this->gameObject->Instatiate(marioTube);
		this->clock.restart();
	}	
		TransformComponent * transform = this->gameObject->GetComponent<TransformComponent*>();
		RigidbodyComponent *rb = this->gameObject->GetComponent<RigidbodyComponent*>();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rb->setAccelY(-0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rb->setAccelY(0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{				
		GameObject *bullet = new GameObject();
		SpriteComponent *bulletSprite = new SpriteComponent();
		TransformComponent *bulletTransform = new TransformComponent();	
		ColliderComponent *bulletCollider = new ColliderComponent();
		BulletScript *bs = new BulletScript(pontuacao_);

		bulletSprite->setSprite("bullet.png");
		bulletTransform->setPosition(transform->getPosition().x + 128, transform->getPosition().y + 33);		
		bullet->AddComponent(bulletSprite);		
		bullet->AddComponent(bulletTransform);
		bullet->AddComponent(bulletCollider);
		bullet->AddComponent(bs);		
		this->gameObject->Instatiate(bullet);
	}
}