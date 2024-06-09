#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Shape.h"
#include "GameObject.h"
#include "Text.h"

class Game
{
private:

	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

	std::vector<Shape*> objectsToDraw;
	std::list<GameObject*> gameObjects;

	int fps = 0;
public:
	sf::RenderWindow& window;

	bool gameOver;
	const float gravity = 9.81f;

	float deltaTime = 0;
	void Update();
	void SetGameOver();
	Game(sf::RenderWindow& window);
	~Game(); 

	std::string GetExecutablePath();
};