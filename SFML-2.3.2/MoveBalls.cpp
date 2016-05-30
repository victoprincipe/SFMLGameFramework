#include "MoveBalls.h"
using namespace std;

MoveBalls::MoveBalls(GameScene *scene, int num_balls)
{
	num_balls_ = num_balls;
	scene_ = scene;	
}

MoveBalls::MoveBalls(GameObject * balls, int num_balls)
{
	balls_ = balls;
	num_balls_ = num_balls;
	init();
}

void MoveBalls::init()
{	
	Ball *ball = NULL;	
	srand(time(NULL));
	for (int i = 0; i < num_balls_; i++) {
		ball = new Ball(rigidBodies);
		ball->set_position((rand() % 50 + 1.0f), (rand() % 50 + 1.0f));
		ball->set_mass((rand() % 50 + 1.0f) + 20);
		balls_->AddComponent(ball);
		std::cout << (rand() % 50 + 1.0f) << "\n";
	}
}

MoveBalls::~MoveBalls()
{
}

void MoveBalls::Start(GameEngine * game)
{	
}

void MoveBalls::Update(GameEngine * game)
{
	for (int i = 0; i < num_balls_; i++) {
		sf::CircleShape shape = balls_->GetComponent<Ball*>()->getShape();
		std::cout << &shape << "\n";
		game->get_window_()->draw(shape);
	}
}

