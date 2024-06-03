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
	if (game.gameOver) return;
	SpawnCar();

	for (auto i : cars) {
		i->Update();
	}

	CheckCollision();
	CheckForOutOfScreen();
}


CarSpawner::CarSpawner(Game& game, Player* player) : game(game), player(player)
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

void CarSpawner::CheckCollision()
{
	for (auto i : cars) {
		bool collision = CheckCollision(i->rect, player->playerVisual);

		if (collision) game.SetGameOver();
	}
}

bool CarSpawner::CheckCollision(const SR::Rectangle& rect1, const Texture* rect2)
{
	bool xOverlap = rect1.position.x < rect2->position.x + rect2->size.x && rect1.position.x + rect1.size.x > rect2->position.x;

	bool yOverlap = rect1.position.y < rect2->position.y + rect2->size.y && rect1.position.y + rect1.size.y > rect2->position.y;

	return xOverlap && yOverlap;
}

