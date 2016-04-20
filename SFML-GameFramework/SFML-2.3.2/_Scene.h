#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "_Sprite.h"

class _Scene
{
private:
	std::string name;
	std::vector<_Sprite> sprite_list;	
public:
	void set_scene_name(std::string name);
	void add_sprite(_Sprite sprite);
	//std::string get_scene_name();
	_Scene(std::string name);
	void run(sf::RenderWindow& window);
	void process_events(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};

