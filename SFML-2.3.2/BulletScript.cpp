#include "BulletScript.h"

BulletScript::BulletScript(Pontuacao * pontuacao)
{
	pontuacao_ = pontuacao;
}

void BulletScript::Start(GameEngine *game)
{

}

void BulletScript::Update(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	transform->move(20, 0);	
	for (int i = 0; i < this->gameObject->gameScene->gameObjectsSize; i++)
	{
		ColliderComponent *thisObject = this->gameObject->GetComponent<ColliderComponent*>();		
			
			if (this->gameObject->gameScene->gameObjects[i]->getName() == "enemy")
			{		
			ColliderComponent *anotherObject = this->gameObject->gameScene->gameObjects[i]->GetComponent<ColliderComponent*>();
			if (anotherObject != NULL && thisObject != anotherObject)
			{				
				if (thisObject->getRect().intersects(anotherObject->getRect()))
				{					
					this->gameObject->Destroy(this->gameObject->gameScene->gameObjects[i]);					
					this->gameObject->Destroy(this->gameObject);
					pontuacao_->incrementar_pontuacao();
				}
			}
		}
	}
	if (transform->getPosition().x > game->get_width_())
	{
		this->gameObject->Destroy(this->gameObject);
	}
}
