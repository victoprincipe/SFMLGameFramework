#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "AbstractScene.h"

class AbstractScene;

class Game
{
public:
	sf::RenderWindow *window;
private:	
	AbstractScene *runningScene;
	std::vector<AbstractScene*> sceneList;
	//FAZER OS SETS E GETS
	sf::String title;
	int width;
	int height;	
private:	
	void start();
	void update();
	void render();
public:
	void run();
	void addScene(AbstractScene *scene);
	Game(int width, int height, sf::String title);
	~Game();
};

