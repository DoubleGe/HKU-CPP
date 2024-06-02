#pragma once
#include "GameObject.h"
#include "Game.h"
#include "Rectangle.h"

class AICar : public GameObject
{
private:
	Game& game;
	SR::Rectangle rectangle;

	float initVelocity = 0;
	float acceleration = 1;
	float lifeTime;
	Vector2 velocity = Vector2(0, 0);

	Vector2 initPos;

	void MoveCar();
public:
	Vector2 position;

	void Update();
	void Draw(sf::RenderWindow& window);

	AICar(Game& game);
};

