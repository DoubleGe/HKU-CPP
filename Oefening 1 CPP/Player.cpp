#include "Player.h"
#include "iostream"

void Player::Update()
{
	if (game.gameOver) return;
	Input();
	CalculatePhysics();
}

void Player::Draw(sf::RenderWindow& window)
{
	playerShape.Draw(window);
}

void Player::Input()
{
	userInput = Vector2(0, 0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		userInput.x = -200;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		userInput.x = 200;
	}
}

void Player::CalculatePhysics()
{
	float fn = weight * game.gravity;
	float ff = friction * fn;
	
	Vector2 frictionAcceleration;
	frictionAcceleration.x = -ff / weight * (velocity.x / std::max(1.0f, std::abs(velocity.x)));
	frictionAcceleration.y = -ff / weight * (velocity.y / std::max(1.0f, std::abs(velocity.y)));
	
	acceleration = (userInput - userInput * (friction * friction)) + frictionAcceleration;

	velocity += acceleration * game.deltaTime;
	
	if (velocity.x > -.1f && velocity.x < .1f) velocity.x = 0;
	if (velocity.y > -.1f && velocity.y < .1f) velocity.y = 0;

	//std::cout << velocity << std::endl;

	position += velocity * game.deltaTime;
	playerShape.SetPosition(position);
}

Player::Player(Vector2 position, Game& game) : game(game)
{
	this->position = position;
	
	playerShape = SR::Rectangle(position.x, position.y, sf::Color(43, 196, 0, 255), Vector2(40, 70));
}

//Player::~Player()
//{
	//delete playerShape;
//}
