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
	playerVisual->Draw(window);
}

void Player::Input()
{
	userInput = Vector2(0, 0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		userInput.x = -250;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		userInput.x = 250;
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
	Vector2 newPositionCalc = position + velocity * game.deltaTime;
	if (newPositionCalc.x < 0) velocity = Vector2(0, 0);
	else if (newPositionCalc.x > game.window.getSize().x - playerVisual->size.x) velocity = Vector2(0, 0);

	position += velocity * game.deltaTime;
	playerVisual->SetPosition(position);
}

Player::Player(Vector2 position, sf::String spritePath, Game& game) : game(game)
{
	this->position = position;
	
	playerVisual = new Texture(spritePath, position);
	playerVisual->SetSize(Vector2(52, 70));
}

Player::~Player()
{
	delete playerVisual;
}
