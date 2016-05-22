#include "MoverCano.h"


void MoverCano::Start(GameEngine *game)
{

}

void MoverCano::Update(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	transform->move(-1, 0);
}
