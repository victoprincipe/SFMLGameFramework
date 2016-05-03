#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameEngine.h"
#include "IntroState.h"
#include "Scene2.h"


int main()
{	
	GameEngine game(1280, 720, "Teste1");
	game.push_scene(IntroState::Instance());
	game.push_scene(Scene2::Instance());
	game.setIcon("sfmlIcon.png");
	game.init();
	return 0;
}