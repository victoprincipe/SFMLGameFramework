#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AbstractScene.h"



class AbstractScene;

class Game
{
public:
	enum GAMESTATE
	{
		RUNNING,
		PAUSED,
	};
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
	//COLOCAR GAMESTATE COMO PRIVADO E FAZER SET GET
	GAMESTATE gameState;
	sf::Event event;	
	void run();
	void init();
	void addScene(AbstractScene *scene);
	Game(int width, int height, sf::String title);
	~Game();
};

