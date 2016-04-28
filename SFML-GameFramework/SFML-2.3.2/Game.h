#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Scene.h"

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode *vm;	
	//ADD GETTER SETTERS
	sf::Image icon;
	sf::String title;
	int width;
	int height;
	int frameRate;
public:
	Game(sf::String title, int width, int height);
	~Game();
};

