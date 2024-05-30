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

	//sf::Font gameFont;
	Text fpsText;

	int fps = 0;
	void LoadFont();
public:
	sf::RenderWindow& window;

	float deltaTime = 0;
	void Update();
	Game(sf::RenderWindow& window);
	~Game(); 

	std::string GetExecutablePath();
};