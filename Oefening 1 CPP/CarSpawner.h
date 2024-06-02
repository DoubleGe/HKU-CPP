#pragma once
#include "GameObject.h";
#include "list"
#include "AICar.h"
#include "Game.h"
#include "Text.h"

class CarSpawner : public GameObject
{
private:
	std::list<AICar*> cars;
	Game& game;

	Text scoreText;
	int currentScore;

	float currentSpawnTimer;
	float timeBetweenSpawn;
	
	void SpawnCar();
	void CheckForOutOfScreen();
	void ChangeScore(int score);
public:
	void Update();
	void Draw(sf::RenderWindow& window);

	CarSpawner(Game& game);
	virtual ~CarSpawner();
};

