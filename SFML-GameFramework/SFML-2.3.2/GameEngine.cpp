#include "GameEngine.h"
#include "GameState.h"

GameEngine::GameEngine(int width, int height, std::string title) 
{
	window_ = new sf::RenderWindow(sf::VideoMode(width, height), title);	
	this->width = width;
	this->height = height;	
}

void GameEngine::init()
{
	this->window_->setFramerateLimit(60);
	running = true;
	output_menssage("GameEngine Init\n");
}

void GameEngine::clean_up() 
{		
	// limpa todos os estados
	while (!states_.empty()) {
		states_.back()->clean_up();
		states_.pop_back();
	}

	output_menssage("GameEngine Cleanup\n");	
	window_->close();
}

void GameEngine::change_state(GameState* state) 
{
	// limpa o estado atual
	if (!states_.empty()) {
		states_.back()->clean_up();
		states_.pop_back();
	}

	// armazena e inicializa o novo estado
	states_.push_back(state);
	states_.back()->init();
}

inline void GameEngine::push_state(GameState* state) {
	
	// pausa o estado atual
	if (!states_.empty()) {
		states_.back()->pause();
	}

	// armazena e inicializa o novo estado
	states_.push_back(state);
	states_.back()->init();
}

inline void GameEngine::pop_state() 
{
	// limpa o estado atual
	if (!states_.empty()) {
		states_.back()->clean_up();
		states_.pop_back();
	}

	// continua o estado anterior
	if (!states_.empty()) {
		states_.back()->resume();
	}	
}

void GameEngine::HandleEvents()
{
	// gerencia o evento atual
	states_.back()->HandleEvents(this);
}

void GameEngine::Draw() 
{
	// desenha o estado na tela
	states_.back()->Draw(this);
}

void GameEngine::update()
{
	// atualiza o estado do jogo
	states_.back()->update(this);
}



GameEngine::~GameEngine()
{
	clean_up();
}

void GameEngine::output_menssage(const char * msg)
{
	std::cout << msg;
}
