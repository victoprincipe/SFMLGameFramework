#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class GameState;

// Gerencia os recursos da janela principal e os estados do jogo.
class GameEngine {
public:	
	GameEngine(int height, int width, std::string title);
	void init();
	void clean_up();

	void change_state(GameState* state);
	inline void push_state(GameState* state);
	inline void pop_state();

	void HandleEvents();
	void Draw();
	void update();

	inline bool is_running() {
		return running;
	};
	inline void quit() {
		running = false;
	}

	inline std::string get_title_() {return title; }
	inline int get_height_() { return height; }
	inline int get_width_() { return width; }
	inline sf::RenderWindow* get_window_() { return window_; }

	~GameEngine();	

private:
	bool running;
	std::vector<GameState*> states_;
	sf::RenderWindow* window_;
	int width;
	int height;
	std::string title;

	void output_menssage(const char* msg);
};
