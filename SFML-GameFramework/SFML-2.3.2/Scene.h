#pragma once
#include <SFML/Graphics.hpp>
#include "AbstractScene.h"

class Scene : public AbstractScene
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void start() override;
	void update() override;
	void render() override;
	Scene();
	~Scene();
};

