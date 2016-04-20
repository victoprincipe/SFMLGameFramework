#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject : public sf::Drawable, public sf::Transformable
{
private:
	sf::String name;
	sf::String tag;
	sf::Texture texture;
	sf::Sprite sprite;	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	GameObject(sf::String name);
	~GameObject();
	void setName(sf::String name);
	void setTexture(sf::String path);
};

