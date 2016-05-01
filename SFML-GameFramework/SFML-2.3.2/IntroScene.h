#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AbstractScene.h"
#include "GameEngine.h"

class IntroScene : public AbstractScene
{
public:
	IntroScene() {};

	void start() override;
	void update() override {};
	void render() override {};

	void update(GameEngine* game);
	void render(GameEngine* game);
	~IntroScene() {};

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
};