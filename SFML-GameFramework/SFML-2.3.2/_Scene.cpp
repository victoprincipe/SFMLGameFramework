#include "_Scene.h"



_Scene::_Scene(std::string name)
{	
	this->name = name;
}

void _Scene::set_scene_name(std::string name)
{
	this->name = name;
}
/*
std::string _Scene::get_scene_name()
{
	return this->set_scene_name;
}
*/
void _Scene::add_sprite(_Sprite sprite)
{
	this->sprite_list.push_back(sprite);
}

void _Scene::process_events(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			window.close();
		}
	}
}

void _Scene::update(sf::RenderWindow& window)
{

}

void _Scene::render(sf::RenderWindow& window)
{	
	window.clear();
	for  (int i = 0;i < sprite_list.size();i++)
	{
		window.draw(sprite_list[i].getSprite());
	}	
	window.display();	
}

void _Scene::run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		process_events(window);
		update(window);
		render(window);
	}	
}
