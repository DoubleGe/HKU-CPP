#pragma once
#include "GameObject.h";
#include "list"
#include "AICar.h"
#include "Game.h"
#include "Text.h"
#include "Player.h"

class CarSpawner : public GameObject
{
private:
	std::list<AICar*> cars;
	Game& game;
	Player* player;

	Text scoreText;
	int currentScore;

	float currentSpawnTimer;
	float timeBetweenSpawn;
	int spawnCount = 1;

	void SpawnCar();
	void ChangeSpawning();
	void CheckForOutOfScreen();
	void ChangeScore(int score);
	void CheckCollision();
	bool CheckCollision(const SR::Rectangle& rect1, const Texture* rect2);
public:
	void Update();
	void Draw(sf::RenderWindow& window);

	CarSpawner(Game& game, Player* player);
	virtual ~CarSpawner();
};

