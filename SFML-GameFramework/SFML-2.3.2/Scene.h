#pragma once
#include <vector>
#include "AbstractScene.h"
#include "GameObject.h"

class Scene : AbstractScene
{
private:
	sf::Texture *marioTexture;
	sf::Sprite *mario;
private:	
	void start() override;
	void update() override;
	void render() override;
public:
	Scene(sf::RenderWindow *window);	
	~Scene();
};

