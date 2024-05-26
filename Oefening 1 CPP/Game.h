#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Shape.h"
#include "GameObject.h"
#include "Text.h";

class Game
{
private:
	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

	std::list<Shape*> objectsToDraw;
	std::list<GameObject*> gameObjects;

	Text fpsText;

	float fps = 0;
public:
	sf::RenderWindow& window;

	float deltaTime = 0;
	void Update();
	Game(sf::RenderWindow& window);
	~Game(); 
};

