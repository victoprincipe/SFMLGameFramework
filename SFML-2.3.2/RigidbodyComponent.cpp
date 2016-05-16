#include "RigidbodyComponent.h"



RigidbodyComponent::RigidbodyComponent()
{	
	this->gravity = 1.0f;
	this->velocityX = 0.0f;
	this->velocityY = 0.0f;
}

RigidbodyComponent::~RigidbodyComponent()
{
}

void RigidbodyComponent::setVelocityX(float velocityX)
{
	this->velocityX = velocityX;
}

void RigidbodyComponent::setVelocityY(float velocityY)
{
	this->velocityY = velocityY;
}

float RigidbodyComponent::getVelocityX()
{
	return this->velocityX;
}

float RigidbodyComponent::getVelocityY()
{
	return this->velocityY;
}

void RigidbodyComponent::overlap()
{		
	ColliderComponent *thisObject = this->gameObject->GetComponent<ColliderComponent*>();
	ColliderComponent *anotherObject;
	if (!thisObject->isKinematic())
	{
		for (std::vector<GameObject*>::iterator it = this->gameObject->gameScene->gameObjects.begin(); it != this->gameObject->gameScene->gameObjects.end(); it++)
		{
			anotherObject = (*it)->GetComponent<ColliderComponent*>();
			if (anotherObject != NULL && thisObject != anotherObject)
			{
				if (thisObject->getX() + thisObject->getWidth() >= anotherObject->getX() && thisObject->getX() <= anotherObject->getX() + anotherObject->getWidth()
					&& thisObject->getY() + thisObject->getHeight() >= anotherObject->getY() && thisObject->getY() <= anotherObject->getY() + anotherObject->getHeight())
				{
					float overlapX = ((thisObject->getWidth() + anotherObject->getWidth()) / 2.0f) - std::abs(thisObject->getX() - anotherObject->getX());
					float overlapY = ((thisObject->getHeight() + anotherObject->getHeight()) / 2.0f) - std::abs(thisObject->getHeight() - anotherObject->getHeight());
					TransformComponent *thisObjectTransform = this->gameObject->GetComponent<TransformComponent*>();
					TransformComponent *anotherObjectTransform = (*it)->GetComponent<TransformComponent*>();
					if (overlapX > overlapY)
					{
						if (this->gravity > 0.0f)
						{
							thisObjectTransform->setPosition(thisObjectTransform->getPosition().x, thisObjectTransform->getPosition().y - (overlapY/2));
						}
						else
						{
							thisObjectTransform->setPosition(thisObjectTransform->getPosition().x, thisObjectTransform->getPosition().y + (overlapY / 2));
						}
					}
					else
					{
						if (thisObjectTransform->getPosition().x > anotherObjectTransform->getPosition().x)
						{
							thisObjectTransform->setPosition(thisObjectTransform->getPosition().x + (overlapX/2), thisObjectTransform->getPosition().y);
						}
						else
						{
							thisObjectTransform->setPosition(thisObjectTransform->getPosition().x - (overlapX/2), thisObjectTransform->getPosition().y);
						}
					}
				}
			}
		}
	}	
}

void RigidbodyComponent::Start(GameEngine *game)
{

}

void RigidbodyComponent::Update(GameEngine *game)
{	
	overlap();		
}
