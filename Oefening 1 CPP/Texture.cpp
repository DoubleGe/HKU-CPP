#include "Texture.h"

void Texture::SetPosition(Vector2 position)
{
	this->position = position;
	sprite.setPosition(position.ConvertToSFML());
}

void Texture::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

Texture::Texture(sf::String path) : Shape(0, 0, sf::Color(0,0,0,255))
{
	if (!texture.loadFromFile(path)) return;
	sprite.setTexture(texture);
}
