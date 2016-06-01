/*#include "MusicComponent.h"

MusicComponent::MusicComponent(std::string font_path)
{
	set_font(font_path);
}

void MusicComponent::set_font(std::string path)
{
	if (!font.loadFromFile(path)) {
		std::cout << "file " << path << " not founded";
	}
	text_.setFont(font);
}

void MusicComponent::set_char_size(int pixel_size)
{
	text_.setCharacterSize(pixel_size);
}

void MusicComponent::set_color(sf::Color color)
{
	text_.setColor(color);
}

void MusicComponent::set_style(sf::Text::Style style)
{
	text_.setStyle(style);
}

void MusicComponent::set_string(std::string str)
{
	text_.setString(str);
}

void MusicComponent::set_position(float x, float y)
{
	text_.setPosition(x, y);
}

void MusicComponent::set_origin(float x, float y)
{
	text_.setOrigin(x, y);
}

void MusicComponent::move(float offset_x, float offset_y)
{
	text_.move(offset_x, offset_y);
}

void MusicComponent::rotate(float angle)
{
	text_.rotate(angle);
}

void MusicComponent::scale(float factor_x, float factor_y)
{
	text_.scale(factor_x, factor_y);
}

void MusicComponent::Start(GameEngine * game)
{
}

void MusicComponent::Update(GameEngine * game)
{
	game->get_window_()->draw(text_);
}

MusicComponent::~MusicComponent()
{
}
*/