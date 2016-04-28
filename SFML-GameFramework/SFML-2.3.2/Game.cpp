#include "Game.h"



Game::Game(sf::String title, int width, int height)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->vm = new sf::VideoMode(width, height);
	this->window = new sf::RenderWindow(*this->vm, this->title);
}


Game::~Game()
{
}
