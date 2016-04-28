#include "AbstractScene.h"

void AbstractScene::run(sf::RenderWindow *window)
{
	this->window = window;
	start();
	update();
	this->window->clear();
	render();
	this->window->display();
}


