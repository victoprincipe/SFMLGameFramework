#pragma once
#include <string>
#include "Component.h"
#include "GameEngine.h"
#include "SFML\Graphics\Text.hpp"

class TextComponent :
	public Component
{
public:
	TextComponent();

	void set_font(std::string path);
	void set_char_size(int pixel_size);
	void set_color(sf::Color color);
	void set_style(sf::Text::Style style);	
	void set_string(std::string str);
	void set_position(float x, float y);
	void set_origin(float x, float y);
	void move(float offset_x, float offset_y);
	void rotate(float angle);
	void scale(float factor_x, float factor_y);
	virtual void Start(GameEngine *game) override;
	virtual void Update(GameEngine *game) override;
	~TextComponent();
protected:
	sf::Text text_;	
};	