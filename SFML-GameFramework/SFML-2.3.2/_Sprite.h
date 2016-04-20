#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class _Sprite
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	_Sprite(std::string path, float x, float y);	
	sf::Sprite getSprite();
};

