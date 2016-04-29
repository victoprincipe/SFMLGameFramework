#include "Game.h"


Game::Game(int width, int height, sf::String title)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);	
}


Game::~Game()
{
}
//ADD NA CENA NA LISTA DE CENAS
void Game::addScene(AbstractScene *scene)
{
	scene->setGame(this);
	runningScene = scene;
}
//PEGAR O PRIMEIRO VALOR DA LISTA DE CENAS QUANDO RODAR O run()
void Game::run()
{
	runningScene->start();
	while (this->window->isOpen())
	{
		runningScene->update();
		this->window->clear();
		runningScene->render();
		this->window->display();
	}
}
