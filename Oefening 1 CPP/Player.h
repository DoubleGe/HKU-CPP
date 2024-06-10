#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Vector2.h"
#include "Texture.h"
#include "Game.h"

class Player : public GameObject
{
private:
	Vector2 acceleration = Vector2(0, 0);
	Vector2 velocity = Vector2(0,0);
	float friction = .5f;
	float weight = 100;
	Vector2 userInput = Vector2(0,0);

	Game& game;

	void Input();
	void CalculatePhysics();
public:
	Vector2 position;
	Texture* playerVisual;

	Player(Vector2 position, sf::String spritePath, Game& game);
	virtual ~Player();

	void Update();
	void Draw(sf::RenderWindow& window);

};

