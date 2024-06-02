#include "AICar.h"
#include "iostream"

void AICar::MoveCar()
{
	lifeTime += game.deltaTime;

	position.y += initVelocity * lifeTime + 0.5 * acceleration * (lifeTime * lifeTime);

	rectangle.SetPosition(position);
}

void AICar::Update()
{
	MoveCar();
}

void AICar::Draw(sf::RenderWindow& window)
{
	rectangle.Draw(window);
}

AICar::AICar(Game& game) : game(game)
{
	acceleration = 1;
	initVelocity = 0;
	lifeTime = 0;

	position = Vector2(std::rand() % game.window.getSize().x, -60);
	rectangle = SR::Rectangle(position.x, position.y, sf::Color(255, 0, 0, 255), Vector2(40, 70));
}