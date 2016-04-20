#include <SFML/Graphics.hpp>
#include <iostream>
#include "_Scene_mananger.h"
#include "_Sprite.h"
#include "_Scene.h"

int main()
{
	/*
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);	
	shape.setPosition(sf::Vector2f(100, 200));
	*/
	_Scene_mananger *scene_mananger = new _Scene_mananger();

	_Scene *scene1 = new _Scene("level1");

	_Sprite *mario = new _Sprite("mario.png", 200, 200);

	scene1->add_sprite(*mario);

	scene_mananger->add_scene(scene1);
	scene_mananger->run_scene("level1");
	/*
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
		}

		window.clear();
		window.draw(shape);					
		window.display();
	}
	*/
	return 0;
}