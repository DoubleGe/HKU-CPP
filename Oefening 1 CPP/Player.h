#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "Game.h"

class Player : public GameObject
{
private:
	Vector2 acceleration = Vector2(0, 0);
	Vector2 velocity = Vector2(0,0);
	float friction = .8f;
	float weight = 100;
	Vector2 userInput = Vector2(0,0);

	SR::Rectangle* playerShape;

	float playerSpeed = 5;
	Vector2 position;
	Game& game;

	void Input();
	void CalculatePhysics();
public:
	Player(Vector2 position, Game& game);
	virtual ~Player();

	void Update();
	void Draw(sf::RenderWindow& window);

};

