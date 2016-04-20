#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "_Scene.h"

class _Scene_mananger
{
private:
	sf::RenderWindow window;	
	std::vector<_Scene*> scene_list;
public:
	_Scene_mananger();
	void add_scene(_Scene *scene);
	void run_scene(std::string scene);
	/*
	void run_scene(sf::RenderWindow& window);
	virtual void process_event();
	virtual void update();
	virtual void render();
	*/
};

