#include "CarSpawner.h"
#include "cmath"
#include "iostream"

void CarSpawner::SpawnCar()
{
	currentSpawnTimer += game.deltaTime;

	if (currentSpawnTimer >= timeBetweenSpawn) {
		cars.push_back(new AICar(game));
		currentSpawnTimer = 0;
	}
}

void CarSpawner::Update()
{
	SpawnCar();

	for (auto i : cars) {
		i->Update();
	}

	CheckForOutOfScreen();
}


CarSpawner::CarSpawner(Game& game) : game(game)
{
	scoreText = Text(Vector2(10, 10), sf::Color(0, 0, 0, 255), "Score: 0");
	currentSpawnTimer = 0;
	timeBetweenSpawn = 2;
	currentScore = 0;
std:srand(std::time(0));
}

void CarSpawner::Draw(sf::RenderWindow& window)
{
	for (auto i : cars) {
		i->Draw(window);
	}

	scoreText.Draw(window);
}

void CarSpawner::CheckForOutOfScreen()
{
	auto it = cars.begin();
	while (it != cars.end()) {
		if ((*it)->position.y >= game.window.getSize().y) {
			delete* it;
			it = cars.erase(it);
			ChangeScore(1);
		}
		else it++;
	}
}

CarSpawner::~CarSpawner()
{
	for (auto i : cars) {
		delete i;
	}
}

void CarSpawner::ChangeScore(int score)
{
	currentScore += score;
	scoreText.SetText("Score: " + std::to_string(currentScore));
}

