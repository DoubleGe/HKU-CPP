#include "Game.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Vector2.h"
#include "Player.h"
#include "Windows.h"

Game::Game(sf::RenderWindow& rw) : window(rw)
{
	Text::LoadDefaultFont(GetExecutablePath() + "/arial.ttf");
	//LoadFont();

	objectsToDraw.push_back(new Circle(250, 250, sf::Color(150, 200, 100, 255), 20));
	objectsToDraw.push_back(new SR::Rectangle(500, 500, sf::Color(150, 200, 200, 255), Vector2(200, 200)));

	Vector2 vec = Vector2(1, -2);
	//std::cout << vec.GetLength() << std::endl;
	//std::cout << vec.Normalized() << std::endl;
	//std::cout << vec.ConvertToSFML().y;

	fpsText = Text(Vector2(50, 50), sf::Color(0, 255, 0, 255), sf::String("Brrr"));
	
	gameObjects.push_back(new Player(Vector2(40, 10), *this));
}

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
	for (auto i : objectsToDraw) {
		i->Draw(window);
	}

	for (auto i : gameObjects) {
		i->Update();
	}

	for (auto i : gameObjects) {
		i->Draw(window);
	}

	for (auto i : gameObjects) {
		i->LateUpdate();
	}

	fpsText.SetText(sf::String("FPS: " + std::to_string(fps)));
	fpsText.Draw(window);

	currentTime = clock.getElapsedTime();
	deltaTime = (currentTime.asSeconds() - previousTime.asSeconds());
	fps = 1.0f / deltaTime; // the asSeconds returns a float
	//std::cout << "fps = " << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
	previousTime = currentTime;

}

//Creates string out of Vector2.
std::ostream& operator<<(std::ostream& strm, const Vector2& a) {
	return strm << "(" << a.x << "," << a.y << ")";
}

void Game::LoadFont()
{
	sf::Font font;

	std::string fontPath = GetExecutablePath() + "/arial.ttf";
	if (!font.loadFromFile(fontPath))
	{
		std::cout << "Font not found: " << fontPath << std::endl;
	}
}

std::string Game::GetExecutablePath()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}