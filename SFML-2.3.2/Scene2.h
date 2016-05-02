#pragma once
#include "GameScene.h"

class Scene2 : public GameScene
{
public:
	void init() override;
	void clean_up() override;

	void pause() override;
	void resume() override;

	void HandleEvents(GameEngine* game) override;
	void Draw(GameEngine* game) override;
	void update(GameEngine* game) override;

	static Scene2* Instance();

protected:
	Scene2() {};
	~Scene2() {};
private:
	static Scene2* scene_;
	sf::RenderTexture render_texture_;
	sf::Texture texture_;
	sf::Sprite sprite_;
};

