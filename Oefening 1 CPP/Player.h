#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "Game.h"

class Player : public GameObject
{
private:
	Shape* playerShape;

	float playerSpeed = 5;
	Vector2 position;
	Game& game;

public:
	Player(Vector2 position, Game& game);
	~Player();

	void Update();
	void Draw(sf::RenderWindow& window);

};

