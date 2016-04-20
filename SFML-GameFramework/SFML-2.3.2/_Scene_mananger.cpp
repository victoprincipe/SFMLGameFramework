#include "_Scene_mananger.h"



_Scene_mananger::_Scene_mananger() : window(sf::VideoMode(800, 600, 32), "SFML Application")
{
}


void _Scene_mananger::add_scene(_Scene *scene)
{
	this->scene_list.push_back(scene);
}

void _Scene_mananger::run_scene(std::string scene)
{
	scene_list[0]->run(window);
	/*
	_Scene *s;
	for (int i = 0; i < this->scene_list.size(); i++)
	{
		if (this->scene_list.at(i)->get_scene_name() == scene)
		{
			s = this->scene_list.at(i);
			break;
		}
	}
	*/
}
