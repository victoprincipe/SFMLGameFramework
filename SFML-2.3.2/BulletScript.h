#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "Pontuacao.h"

class BulletScript : public Component
{
public:		
	BulletScript(Pontuacao * pontuacao);
	void Start(GameEngine *game);
	void Update(GameEngine *game);	
private:	
	Pontuacao* pontuacao_;
};

