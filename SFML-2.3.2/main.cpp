#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "GameEngine.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "MoveScript.h"
#include "CameraComponent.h"
#include "GameDataBase.h"
#include "TXTDataBase.h"


void physics(sf::Sprite *s, float *velx, float accelx, float *vely, float accely)
{	
	if (*velx > 0)
	{
		*velx -= 0.05f;
	}
	if (*velx < 0)
	{
		*velx += 0.05f;
	}	
	if (*velx >= -0.05f && *velx <= 0.05f)
	{
		*velx = 0;
	}
	if (*vely > 0)
	{
		*vely -= 0.05f;
	}
	if (*vely < 0)
	{
		*vely += 0.05f;
	}
	if (*vely >= -0.05f && *vely <= 0.05f)
	{
		*vely = 0;
	}	
	*vely += 0.05f;
	*velx += accelx;
	*vely += accely;
	s->setPosition(s->getPosition().x + *velx, s->getPosition().y + *vely);
}

void collider(sf::Sprite *s1, sf::Sprite *s2, float *velX, float *velY, sf::RectangleShape *rs)
{	
	if ( (s1->getPosition().x) >= (s2->getPosition().x) && (s1->getPosition().x + s1->getTextureRect().width) <= (s2->getPosition().x + s2->getTextureRect().width) )
	{
		if ( (s1->getPosition().y) >= (s2->getPosition().y) && (s1->getPosition().y + s1->getTextureRect().width) <= (s2->getPosition().y + s2->getTextureRect().width) )
		{
			*velY = 0;
			rs->setFillColor(sf::Color(255, 0, 0, 255));					
		}		
	}
	else
	{		
		rs->setFillColor(sf::Color(255, 255, 255, 255));
	}
}

void rigidbody(sf::Sprite *s1, sf::Sprite *s2, float *velX, float *velY, bool *colide)
{	
	if (s1->getPosition().x + s1->getTextureRect().width >= s2->getPosition().x && s1->getPosition().x <= s2->getPosition().x + s2->getTextureRect().width
		&& s1->getPosition().y + s1->getTextureRect().height >= s2->getPosition().y && s1->getPosition().y <= s2->getPosition().y + s2->getTextureRect().height)
	{			
		float overlapX = ((s1->getTextureRect().width + s2->getTextureRect().width) / 2.0f) - std::abs(s1->getPosition().x - s2->getPosition().x);
		float overlapY = ((s1->getTextureRect().height + s2->getTextureRect().height) / 2.0f) - std::abs(s1->getPosition().y - s2->getPosition().y);
		if (overlapX > overlapY)
		{
			if (*velY > 0.0f)
			{
				s1->setPosition(s1->getPosition().x, s1->getPosition().y - overlapY);
			}
			else
			{
				s1->setPosition(s1->getPosition().x, s1->getPosition().y + overlapY);
			}			
		}
		else
		{
			if (s1->getPosition().x > s2->getPosition().x)
			{
				s1->setPosition(s1->getPosition().x + overlapX, s1->getPosition().y);
			}
			else
			{
				s1->setPosition(s1->getPosition().x - overlapX, s1->getPosition().y);
			}
		}
	}			
}

int main()
{	
	// Test game data base
	GameDataBase *db = new TXTDataBase();
	db->open("pontos.txt");
	db->save_data("pontuacao maxima", "500");
	db->save_data("pontuacao minima", "501");
	db->save_data("pontuacao media", "499");	
	std::cout << db->load_data("pontuacao minima");
	std::cout << db->load_data("pontuacao media1");
	std::cout << db->load_data("pontuacao maxima");	
	std::cout << db->load_data("pontuacao media");
	std::cout << db->load_data("pontuacao minima");
	db->close();
	


	GameEngine game(1280, 720, "Teste1");

	//CENA 1
	GameScene *scene1 = new GameScene();
	GameObject *mario = new GameObject();
	SpriteComponent *marioSprite = new SpriteComponent();
	TransformComponent *transform = new TransformComponent();
	MoveScript *ms = new MoveScript();
	CameraComponent *camera = new CameraComponent();
	camera->rotateCamera(30);
	marioSprite->setSprite("mario.png");
	transform->setPosition(300,100);
	mario->AddComponent(transform);
	mario->AddComponent(marioSprite);
	mario->AddComponent(ms);	
	mario->AddComponent(camera);
	scene1->addGameObject(mario);

	//CENA 2	
	GameScene *scene2 = new GameScene();
	GameObject *sonic = new GameObject();
	SpriteComponent *sonicSprite = new SpriteComponent();
	TransformComponent *sonicTransform = new TransformComponent();
	MoveScript *msSonic = new MoveScript();
	sonicSprite->setSprite("sonic.png");
	sonicTransform->setPosition(100, 100);
	sonic->AddComponent(sonicTransform);
	sonic->AddComponent(sonicSprite);
	sonic->AddComponent(msSonic);
	scene2->addGameObject(sonic);
	
	game.push_scene(scene1);
	game.push_scene(scene2);	
	game.setIcon("sfmlIcon.png");
	game.init();
	return 0;
	

	/*
	GameObject *go = new GameObject();	
	SpriteComponent *sprite = new SpriteComponent;	
	go->AddComponent(sprite);
	SpriteComponent *x = go->GetComponent<SpriteComponent*>();
	
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	sf::Sprite mario;
	sf::Sprite mario2;
	sf::Texture mTexture;	
	sf::RectangleShape marioRect;
	mario2.setPosition(200,0);
	mTexture.loadFromFile("mario.png");
	mario.setTexture(mTexture);
	mario2.setTexture(mTexture);
	marioRect.setSize((sf::Vector2f)mario.getTexture()->getSize());
	marioRect.setTextureRect(mario.getTextureRect());	
	float vel = 0;
	float vely = 0;
	float accel = 0;
	float accely = 0;
	float lastPosX;
	float lastPosY;
	bool colide = false;
	sf::View view1;		
	int colCout = 0;
	// run the program as long as the window is open
	while (window.isOpen())
	{		
		//std::cout << "VX:" << vel << " VY:" << vely << std::endl;
		lastPosX = mario.getPosition().x;
		lastPosY = mario.getPosition().y;
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//setVelocity(&mario, 0.1f);
			vel += 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//setVelocity(&mario, -0.1f);
			vel += -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{			
			//setVelocity(&mario, 0.1f);
			vely += -4;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{			
			//setVelocity(&mario, -0.1f);
			vely += 4;
		}
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();			
		}		
		mario.setPosition(mario.getPosition().x + vel, mario.getPosition().y + vely);	
		rigidbody(&mario, &mario2, &lastPosX, &vely, &colide);
		if (colide)
		{
			vely = 0;
		}
		else
		{
			vely = 1;
		}		
		mario.setPosition(mario.getPosition().x, mario.getPosition().y + vely);
		//collider(&mario, &mario2, &vel, &vely, &marioRect);					
		float x = mario.getTextureRect().width;
		float y = mario.getTextureRect().height;
		view1.setCenter(mario.getPosition().x + x / 2, mario.getPosition().y + y / 2);
		marioRect.setPosition(mario.getPosition());		
		window.setView(view1);
		window.clear();
		window.draw(marioRect);
		window.draw(mario);
		window.draw(mario2);
		window.display();
		accel = 0;
		accely = 0;
		vel = 0;
		
	}
	*/
	return 0;
}