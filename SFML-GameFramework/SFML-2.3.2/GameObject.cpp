#include "GameObject.h"



GameObject::GameObject(sf::String name)
{
	this->name = name;
}


GameObject::~GameObject()
{
	//delete this;
}

void GameObject::setName(sf::String name)
{
	this->name = name;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite, states);
}

void GameObject::setTexture(sf::String path)
{
	if (!this->texture.loadFromFile(path))
		std::cout << "LOADING IMAGE FAIL" << std::endl;
	else
		this->sprite.setTexture(this->texture);
}
