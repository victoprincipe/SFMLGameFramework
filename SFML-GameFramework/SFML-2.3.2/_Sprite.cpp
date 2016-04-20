#include "_Sprite.h"



_Sprite::_Sprite(std::string path, float x, float y)
{
	if (!this->texture.loadFromFile(path))
	{
		std::cout << "FAILED LOADING TEXTURE" << std::endl;
	}
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

sf::Sprite _Sprite::getSprite()
{
	return this->sprite;
}

