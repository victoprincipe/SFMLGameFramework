#include "MoverCano.h"


void MoverInimigo::Start(GameEngine *game)
{

}

void MoverInimigo::Update(GameEngine *game)
{
	TransformComponent *transform = this->gameObject->GetComponent<TransformComponent*>();
	transform->move(-1, 0);
}
