#pragma once
#include "Component.h"
#include "SpriteComponent.h"

class ColliderComponent : public Component
{
private:
	float x;
	float y;
	float width;
	float height;
	sf::FloatRect rect;
	bool kinematic = false;
public:
	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float hieght);
	sf::FloatRect getRect();
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	void Update(GameEngine *game);
	void Start(GameEngine *game);
	ColliderComponent();
	~ColliderComponent();
	bool isKinematic();
	void setKinematic(bool kinematic);
};

