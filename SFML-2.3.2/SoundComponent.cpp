/*#include "SoundComponent.h"

SoundComponent::SoundComponent(std::string font_path)
{
	set_font(font_path);
}

void SoundComponent::set_font(std::string path)
{
	if (!font.loadFromFile(path)) {
		std::cout << "file " << path << " not founded";
	}
	text_.setFont(font);
}

void SoundComponent::set_char_size(int pixel_size)
{
	text_.setCharacterSize(pixel_size);
}

void SoundComponent::set_color(sf::Color color)
{
	text_.setColor(color);
}

void SoundComponent::set_style(sf::Text::Style style)
{
	text_.setStyle(style);
}

void SoundComponent::set_string(std::string str)
{
	text_.setString(str);
}

void SoundComponent::set_position(float x, float y)
{
	text_.setPosition(x, y);
}

void SoundComponent::set_origin(float x, float y)
{
	text_.setOrigin(x, y);
}

void SoundComponent::move(float offset_x, float offset_y)
{
	text_.move(offset_x, offset_y);
}

void SoundComponent::rotate(float angle)
{
	text_.rotate(angle);
}

void SoundComponent::scale(float factor_x, float factor_y)
{
	text_.scale(factor_x, factor_y);
}

void SoundComponent::Start(GameEngine * game)
{
}

void SoundComponent::Update(GameEngine * game)
{
	game->get_window_()->draw(text_);
}

SoundComponent::~SoundComponent()
{
}
*/