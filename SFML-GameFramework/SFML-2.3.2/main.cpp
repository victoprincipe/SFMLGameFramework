#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"


int main()
{	
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);	
	shape.setPosition(sf::Vector2f(100, 200));
		
	GameObject *a = new GameObject("TEST");
	a->setTexture("mario.png");
	a->setPosition(200, 200);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
		}

		window.clear();
		window.draw(shape);	
		window.draw(*a);
		window.display();
	}
	
	return 0;
}