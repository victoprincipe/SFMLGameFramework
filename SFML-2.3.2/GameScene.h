#pragma once
#include "GameEngine.h"

class GameEngine;

// Interface do estado do jogo. Qualquer estado deve implementar essa abstração.
class GameScene {
public:
	virtual void init() = 0;
	virtual void clean_up() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;
		
	virtual void HandleEvents(GameEngine* game) = 0;	
	virtual void update(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;
protected:
	GameScene() {};
	~GameScene() {};	
private:
	static GameScene* scene_;
};
