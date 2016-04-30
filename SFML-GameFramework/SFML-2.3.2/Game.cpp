#include "Game.h"


Game::Game(int width, int height, sf::String title) : window(new sf::RenderWindow(sf::VideoMode(width, height), title))
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->window->setFramerateLimit(60);	
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
	this->gameState = Game::RUNNING;
	this->start();
	while (this->window->isOpen())
	{
		//ORGANIZAR ESTE WHILE EM METODOS
		while (this->window->pollEvent(event) || true)
		{			
			if (event.type == sf::Event::Closed)
			{
				this->window->close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					if (this->gameState == Game::RUNNING)
						this->gameState = Game::PAUSED;
					else
						this->gameState = Game::RUNNING;
				}
			}
			//ORGANIZAR CADA IF EM METODOS
			if (gameState == Game::RUNNING)
			{
				this->update();
				this->window->clear();
				this->render();
				this->window->display();
			}
			if (gameState == Game::PAUSED)
			{
				this->window->clear();
				runningScene->render();
				this->window->display();
			}
		}		
	}
}

void Game::start()
{
	runningScene->start();
}

void Game::update()
{	
	runningScene->update();
}

void Game::render()
{
	runningScene->render();
}