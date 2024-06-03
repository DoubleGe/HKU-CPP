#include "Texture.h"

void Texture::SetPosition(Vector2 position)
{
	this->position = position;
	sprite.setPosition(position.ConvertToSFML());
}

void Texture::SetSize(Vector2 size)
{
	this->size = size;
}

void Texture::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

Texture::Texture(sf::String path, Vector2 position) : Shape(position.x, position.y, sf::Color(0, 0, 0, 255))
{
	if (!texture.loadFromFile(path)) return;
	sprite.setTexture(texture);
	SetPosition(position);
}

Texture::Texture(sf::String path) : Shape(0, 0, sf::Color(0,0,0,255))
{
	if (!texture.loadFromFile(path)) return;
	sprite.setTexture(texture);
}

Texture::Texture() : Shape(0, 0, sf::Color(0, 0, 0, 255)) { }