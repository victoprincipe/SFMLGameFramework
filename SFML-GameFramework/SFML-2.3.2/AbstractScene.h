#pragma once
#include <SFML/Graphics.hpp>

class AbstractScene
{
protected:
	sf::RenderWindow *window;
protected:	
	void run(sf::RenderWindow *window);
	virtual void start();
	virtual void update();
	virtual void render();
};

