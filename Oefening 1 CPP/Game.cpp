#include "Game.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Vector2.h"
#include "Player.h"
#include "Windows.h"
#include "CarSpawner.h"
#include "Texture.h"

//Create the game handler.
Game::Game(sf::RenderWindow& rw) : window(rw)
{
	Text::LoadDefaultFont(GetExecutablePath() + "/arial.ttf");

	Texture* testTexture = new Texture(GetExecutablePath() + "/RoadSprite.png");
	objectsToDraw.push_back(testTexture);

	sf::String playerPath = GetExecutablePath() + "/PlayerCar.png";
	Player* player = new Player(Vector2(40, window.getSize().y - 100), playerPath, *this);
	gameObjects.push_back(player);

	CarSpawner* carSpawner = new CarSpawner(*this, player);
	carSpawner->LoadCarSprites(GetExecutablePath());
	gameObjects.push_back(carSpawner);
}

//Removes all the *.
Game::~Game()
{
	for (auto i : objectsToDraw) {
		delete i;
	}

	for (auto i : gameObjects) {
		delete i;
	}
}

void Game::Update()
{
	//Draws the "static" objects.
	for (auto i : objectsToDraw) {
		i->Draw(window);
	}

	//Updates the GameObjects
	for (auto i : gameObjects) {
		i->Update();
	}

	//Late update for GameObjects
	for (auto i : gameObjects) {
		i->LateUpdate();
	}

	//Draw for the GameObjects
	for (auto i : gameObjects) {
		i->Draw(window);
	}

	//Calculate the deltaTime & framerate.
	currentTime = clock.getElapsedTime();
	deltaTime = (currentTime.asSeconds() - previousTime.asSeconds());
	fps = 1.0f / deltaTime; 
	previousTime = currentTime;
}

//Sets the state of the game to GameOver
void Game::SetGameOver()
{
	gameOver = true;

	Vector2 textPos = Vector2(window.getSize().x * .5f - 155, window.getSize().y * .5f - 50);
	Text* gameOverText = new Text(textPos, sf::Color(255, 0, 0, 255), "GAME OVER");
	gameOverText->SetBold(true);
	gameOverText->SetSize(50);
	objectsToDraw.push_back(gameOverText);
}

//Creates string out of Vector2.
std::ostream& operator<<(std::ostream& strm, const Vector2& a) {
	return strm << "(" << a.x << "," << a.y << ")";
}

//Gets the path the application is executed in.
std::string Game::GetExecutablePath()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}