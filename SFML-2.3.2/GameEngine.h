#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "GameScene.h"
#include "GameObject.h"
#include "Component.h"

class GameScene;
class GameObject;
class Component;

// Gerencia os recursos da janela principal e os estados do jogo.
class GameEngine {
public:	
	GameEngine(int height, int width, sf::String title);
	void init();	
	
	void change_scene(int index);
	void push_scene(GameScene* scene);
	void setIcon(sf::String path);
	float getDeltaTime();
	
	std::string get_title_() {return title; }
	int get_height_() { return height; }
	int get_width_() { return width; }

	sf::RenderWindow* get_window_() { return window_; }		
private:
	void game_loop();	
	void Start();
	void Update();
private:
	bool running;		
	GameScene *running_scene_;
	std::vector<GameScene*> scenes_;
	sf::RenderWindow* window_;
	sf::String title;	
	sf::Clock clock;
	float deltaTime;
	int width;
	int height;	
};
