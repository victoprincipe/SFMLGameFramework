#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine.h"

class Input
{
private:
	float horizontal_axis_;
	float vertical_axis_;
public:
	void eventHandling(GameEngine *game);
	Input();
	~Input();
};

