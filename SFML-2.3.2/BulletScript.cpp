#include "BulletScript.h"

void BulletScript::Start(GameEngine *game)
{

}

void BulletScript::Update(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	transform->move(20, 0);	
	for (std::vector<GameObject*>::iterator it = this->gameObject->gameScene->gameObjects.begin(); it != this->gameObject->gameScene->gameObjects.end(); it++)
	{
		ColliderComponent *thisObject = this->gameObject->GetComponent<ColliderComponent*>();
		if ((*it)->getName() == "enemy")
		{			
			ColliderComponent *anotherObject = (*it)->GetComponent<ColliderComponent*>();			
			if (anotherObject != NULL && thisObject != anotherObject)
			{			
				std::cout << anotherObject->getX();
				if (thisObject->getX() + thisObject->getWidth() >= anotherObject->getX() && thisObject->getX() <= anotherObject->getX() + anotherObject->getWidth()
					&& thisObject->getY() + thisObject->getHeight() >= anotherObject->getY() && thisObject->getY() <= anotherObject->getY() + anotherObject->getHeight())
				{					
					(*it)->setEnable(false);
				}
			}

		}
	}
}