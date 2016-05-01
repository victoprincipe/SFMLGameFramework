#pragma once
#include "GameEngine.h"

// Interface do estado do jogo. Qualquer estado deve implementar essa abstração.
class GameState {
public:
	virtual void init() = 0;
	virtual void clean_up() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	void change_state(GameEngine* game, GameState* state) {
		game->change_state(state);
	}

	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;
	virtual void update(GameEngine* game) = 0;

protected:
	GameState() {};
	~GameState() {};
private:

};
