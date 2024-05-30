#include "Player.h"

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position.y -= 100 * game.deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position.y += 100 * game.deltaTime;
	}

	playerShape->SetSize(playerShape->GetSize() + Vector2(1, 1) * game.deltaTime);

	playerShape->SetPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
	playerShape->Draw(window);
}

Player::Player(Vector2 position, Game& game) : game(game)
{
	this->position = position;
	
	playerShape = new SR::Rectangle(position.x, position.y, sf::Color(255, 0, 0, 255), Vector2(10, 10));
}

Player::~Player()
{
	delete playerShape;
}
