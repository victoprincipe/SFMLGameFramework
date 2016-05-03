#pragma once
#include "GameEngine.h"
#include "Scene.h"

class GameEngine;
class Scene;

// Instancia de um estado introdutório do jogo
class IntroState : public GameState {
public:
	IntroState(AbstractScene* scene, EventHandler* event_handler) : 
		GameState(scene, event_handler) {};
	
	void pause() override;
	void resume() override;

	static IntroState* Instance(AbstractScene * scene, EventHandler * event_handler);

	static IntroState* Instance();
	~IntroState() {};
private:		
	static IntroState* intro_state_;		
};