#include "CarSpawner.h"
#include "cmath"
#include "iostream"

//Spawns a car when the timer hits the intverval.
void CarSpawner::SpawnCar()
{
	currentSpawnTimer += game.deltaTime;


	if (currentSpawnTimer >= timeBetweenSpawn) {
		for (size_t i = 0; i < spawnCount; i++)
		{
			int randomIndex = rand() % carTextures.size();

			cars.push_back(new AICar(game, carTextures[randomIndex]));
			currentSpawnTimer = 0;
		}
	}
}

//Sets the spawning speed + ammount.
void CarSpawner::ChangeSpawning()
{
	switch (currentScore) {
	case 5:
		timeBetweenSpawn -= .25f;
		break;
	case 10:
		spawnCount++;
		break;
	case 15:
		timeBetweenSpawn -= .25f;
		break;
	case 30:
		spawnCount++;
		break;
	case 50:
		timeBetweenSpawn -= .25f;
		break;
	case 75:
		spawnCount++;
		break;
	case 130:
		timeBetweenSpawn -= .25f;
		break;
	case 160:
		spawnCount++;
		break;
	}
}

//Updates the CarSpawner Object.
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


//Creates the CarSpawner obj.
CarSpawner::CarSpawner(Game& game, Player* player) : game(game), player(player)
{
	scoreText = Text(Vector2(10, 10), sf::Color(0, 0, 0, 255), "Score: 0");
	currentSpawnTimer = 0;
	timeBetweenSpawn = 2;
	currentScore = 0;
	std:srand(std::time(0)); //Sets random seed based on time.
}

//Draws all the cars & Score text.
void CarSpawner::Draw(sf::RenderWindow& window)
{
	for (auto i : cars) {
		i->Draw(window);
	}

	scoreText.Draw(window);
}

void CarSpawner::LoadCarSprites(sf::String basePath)
{
	//Lazy way (I know). Best way is to use a list with the sprite name instead of full name.
	carTextures.push_back(sf::String(basePath + sf::String("/Sprites/Cars/GreenCar.png")));
	carTextures.push_back(sf::String(basePath + sf::String("/Sprites/Cars/YellowCar.png")));
	carTextures.push_back(sf::String(basePath + sf::String("/Sprites/Cars/PinkCar.png")));
	carTextures.push_back(sf::String(basePath + sf::String("/Sprites/Cars/YellowCar.png")));
}

//Checks for Out of screen and deletes it.
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

//Removes all the cars
CarSpawner::~CarSpawner()
{
	for (auto i : cars) {
		delete i;
	}
}

//Change the player score.
void CarSpawner::ChangeScore(int score)
{
	currentScore += score;
	scoreText.SetText("Score: " + std::to_string(currentScore));
	ChangeSpawning();
}

//Checks for collision with the player
void CarSpawner::CheckCollision()
{
	for (auto i : cars) {
		bool collision = CheckCollision(i->aiCarTexture, player->playerVisual);

		if (collision) game.SetGameOver();
	}
}

//The actual Collision check between shapes.
bool CarSpawner::CheckCollision(const Texture* rect1, const Texture* rect2)
{
	bool xOverlap = rect1->position.x < rect2->position.x + rect2->size.x && rect1->position.x + rect1->size.x > rect2->position.x;

	bool yOverlap = rect1->position.y < rect2->position.y + rect2->size.y && rect1->position.y + rect1->size.y > rect2->position.y;

	return xOverlap && yOverlap;
}

