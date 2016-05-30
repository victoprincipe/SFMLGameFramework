#include "GameEngine.h"
#include "GameScene.h"

GameEngine::GameEngine(int width, int height, sf::String title) 
{
	window_ = new sf::RenderWindow(sf::VideoMode(width, height), title);	
	this->width = width;
	this->height = height;
	this->title = title;	
}

void GameEngine::init()
{	
	this->running_scene_ = this->scenes_[0];
	this->window_->setFramerateLimit(60);	
	this->running = true;
	this->Start();
	this->game_loop();	
}


void GameEngine::setIcon(sf::String path)
{
	sf::Image icon;
	icon.loadFromFile(path);
	this->get_window_()->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void GameEngine::Instatiate(GameObject *go)
{
	this->running_scene_->addGameObject(go);
}

void GameEngine::game_loop()
{
	while (this->get_window_()->isOpen()) 
	{	
		this->get_window_()->clear();
		sf::Time elapsedTime = this->clock.restart();		
		this->Update();
		this->deltaTime = elapsedTime.asMilliseconds();				
		this->get_window_()->display();
	}
}

float GameEngine::getDeltaTime()
{
	return this->deltaTime;
}

void GameEngine::change_scene(int index) 
{
	this->running_scene_ = scenes_[index];
	this->running_scene_->Start(this);
}

void GameEngine::push_scene(GameScene* scene) 
{	
	scenes_.push_back(scene);
}

void GameEngine::Start() 
{
	// desenha o estado na tela
	running_scene_->Start(this);
}

void GameEngine::Update()
{
	// atualiza o estado do jogo
	running_scene_->Update(this);
}