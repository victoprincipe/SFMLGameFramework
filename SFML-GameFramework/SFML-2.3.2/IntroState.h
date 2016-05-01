#pragma once
#include "GameEngine.h"
#include "Scene.h"

class GameEngine;
class Scene;

// Instancia de um estado introdutório do jogo
class IntroState : public GameState {
public:
	void init() override;
	void clean_up() override;

	void pause() override;
	void resume() override;

	void HandleEvents(GameEngine* game) override;
	void Draw(GameEngine* game) override;
	void update(GameEngine* game) override;

	static IntroState* Instance();

protected:	
	IntroState() {};
	~IntroState() {};
private:		
	static IntroState* intro_state_;	
	sf::RenderTexture render_texture_;
	sf::Texture texture_;
	sf::Sprite sprite_;
};