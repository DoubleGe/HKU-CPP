#include "Player.h"
#include "iostream"

//Updates the player loop.
void Player::Update()
{
	if (game.gameOver) return;
	Input();
	CalculatePhysics();
}

//Draws the player.
void Player::Draw(sf::RenderWindow& window)
{
	playerVisual->Draw(window);
}

//Handles player Input.
void Player::Input()
{
	userInput = Vector2(0, 0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		userInput.x = -1500;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		userInput.x = 1500;
	}
}

//Calculate the player physics.
void Player::CalculatePhysics()
{
	float fn = weight * game.gravity;
	float ff = friction * fn;
	
	Vector2 frictionAcceleration;
	frictionAcceleration.x = -ff / weight * velocity.x;
	frictionAcceleration.y = -ff / weight * velocity.y;
	
	acceleration = (userInput - userInput * (friction * friction)) + frictionAcceleration;

	velocity += acceleration * game.deltaTime;
	
	//Stops the velocity if it's too small (Stopts tiny movements).
	if (velocity.x > -.1f && velocity.x < .1f) velocity.x = 0;
	if (velocity.y > -.1f && velocity.y < .1f) velocity.y = 0;

	//Checks if the new position isn't out of bounce.
	Vector2 newPositionCalc = position + velocity * game.deltaTime;
	if (newPositionCalc.x < 0) velocity = Vector2(0, 0);
	else if (newPositionCalc.x > game.window.getSize().x - playerVisual->size.x) velocity = Vector2(0, 0);

	position += velocity * game.deltaTime;
	playerVisual->SetPosition(position);
}

//Creates the player
Player::Player(Vector2 position, sf::String spritePath, Game& game) : game(game)
{
	this->position = position;
	
	playerVisual = new Texture(spritePath, position);
	playerVisual->SetSize(Vector2(52, 70));
}

//Removes Player visual
Player::~Player()
{
	delete playerVisual;
}
