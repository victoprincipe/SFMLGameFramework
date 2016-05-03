#pragma once
#include "GameEngine.h"
#include "AbstractScene.h"
#include "EventHandler.h"

class AbstractScene;
class EventHandler;

// Interface do estado do jogo. Qualquer estado deve implementar essa abstração.
class GameState {
public:
	GameState(AbstractScene* scene, EventHandler* event_handler):
		scene_(scene), event_handler_(event_handler) {};

	virtual void init();
	virtual void clean_up();

	virtual void pause() {};
	virtual void resume() {};

	void change_state(GameEngine* game, GameState* state) {
		game->change_state(state);
	}

	void HandleEvents(GameEngine* game);
	void Draw(GameEngine* game);
	void update(GameEngine* game);

	inline AbstractScene* get_scene_() { return scene_; }
	inline EventHandler* get_event_handler() { return event_handler_; }

	~GameState() { clean_up(); };
protected:	

	AbstractScene* scene_;
	EventHandler* event_handler_;
private:

};
