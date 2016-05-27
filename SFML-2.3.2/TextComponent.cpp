#include "TextComponent.h"

TextComponent::TextComponent(std::string font_path) 
{		
	set_font(font_path);
}

void TextComponent::set_font(std::string path)
{	
	if (!font.loadFromFile(path)) {
		std::cout << "file " << path << " not founded";
	}
	text_.setFont(font);
}

void TextComponent::set_char_size(int pixel_size)
{
	text_.setCharacterSize(pixel_size);
}

void TextComponent::set_color(sf::Color color)
{
	text_.setColor(color);
}

void TextComponent::set_style(sf::Text::Style style)
{
	text_.setStyle(style);
}

void TextComponent::set_string(std::string str)
{
	text_.setString(str);
}

void TextComponent::set_position(float x, float y)
{
	text_.setPosition(x, y);
}

void TextComponent::set_origin(float x, float y)
{
	text_.setOrigin(x, y);
}

void TextComponent::move(float offset_x, float offset_y)
{
	text_.move(offset_x, offset_y);
}

void TextComponent::rotate(float angle)
{
	text_.rotate(angle);
}

void TextComponent::scale(float factor_x, float factor_y)
{
	text_.scale(factor_x, factor_y);
}

void TextComponent::Start(GameEngine * game)
{
}

void TextComponent::Update(GameEngine * game)
{
	game->get_window_()->draw(text_);	
}

TextComponent::~TextComponent()
{
}
