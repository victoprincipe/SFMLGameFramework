#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "TextComponent.h"
#include "GameDataBase.h"
#include "SQLiteDataBase.h"

class BulletScript : public Component
{
public:
	BulletScript();
	void Start(GameEngine *game);
	void Update(GameEngine *game);
	~BulletScript() {}
	//static int SCORE;
private:
	GameDataBase * db;	
};

