#include "BulletScript.h"

BulletScript::BulletScript() 
{
	//score_ = 0;
	//db = new SQLiteDataBase();
}

BulletScript::BulletScript(int * score)
{
	this->score = score;
}

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
				//std::cout << anotherObject->getX();
				if (thisObject->getX() + thisObject->getWidth() >= anotherObject->getX() && thisObject->getX() <= anotherObject->getX() + anotherObject->getWidth()
					&& thisObject->getY() + thisObject->getHeight() >= anotherObject->getY() && thisObject->getY() <= anotherObject->getY() + anotherObject->getHeight())
				{					
					(*it)->setEnable(false);
					//BulletScript::SCORE++;
					//std::cout << BulletScript::SCORE++;
					/*
					score_ = db->load_int_data("pontos");
					db->save_data("pontos", score_++, 0, 0);					
					TextComponent * text = this->gameObject->GetComponent<TextComponent*>();					
					text->set_string(std::string("score: " + score_));*/
					(*score)++;
				}
			}

		}
	}
}