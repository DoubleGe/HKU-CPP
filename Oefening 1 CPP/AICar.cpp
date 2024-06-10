#include "AICar.h"
#include "iostream"

//Moves the car with a constant accelaration.
void AICar::MoveCar()
{
	lifeTime += game.deltaTime;

	position.y += initVelocity * lifeTime + 0.5 * acceleration * (lifeTime * lifeTime);

	aiCarTexture->SetPosition(position);
}

void AICar::Update()
{
	MoveCar();
}

//Draws the AI Car.
void AICar::Draw(sf::RenderWindow& window)
{
	aiCarTexture->Draw(window);
}

//Creates the AICar
AICar::AICar(Game& game, sf::String spriteToUse) : game(game)
{
	acceleration = 1;
	initVelocity = 0;
	lifeTime = 0;

	position = Vector2(std::rand() % game.window.getSize().x - 60, -60);

	//Loads new sprite because textures need to be a * otherwise the game won't render them.
	//Tried it with sprites form the spawner, but you can't only draw a sprite it also contains the position.
	aiCarTexture = new Texture(spriteToUse);
	aiCarTexture->SetSize(Vector2(52, 75));
}

AICar::~AICar()
{
	delete aiCarTexture;
}
