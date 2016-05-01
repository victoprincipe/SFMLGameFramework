#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Game.h"
#include "GameEngine.h"
#include "IntroState.h"

int main()
{	
	GameEngine game(1280, 720, "Teste1");

	game.init();
	game.change_state(IntroState::Instance());
	
	while (game.is_running()) {
		game.HandleEvents();
		game.update();
		game.Draw();
	}

	game.clean_up();
	
	/*
	Game *game = new Game(1280, 720, "Test");
	Scene *scene = new Scene();
	game->addScene(scene);
	game->run();
	//game->init();
	/*
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);			
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);			
		window.display();
	}
	*/
	return 0;
}