#include "Texture.h"

//Sets the position
void Texture::SetPosition(Vector2 position)
{
	this->position = position;
	sprite.setPosition(position.ConvertToSFML());
}

//Sets the size of the texture (Not used for texture size only for the collision).
void Texture::SetSize(Vector2 size)
{
	this->size = size;
}

//Draws the sprite
void Texture::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

//Creates Texture on the location
Texture::Texture(sf::String path, Vector2 position) : Shape(position.x, position.y, sf::Color(0, 0, 0, 255))
{
	if (!texture.loadFromFile(path)) return;
	sprite.setTexture(texture);
	SetPosition(position);
}

//Creates a texture only the path.
Texture::Texture(sf::String path) : Shape(0, 0, sf::Color(0,0,0,255))
{
	if (!texture.loadFromFile(path)) return;
	sprite.setTexture(texture);
}

//Creates Empty Texture (Don't use)
Texture::Texture() : Shape(0, 0, sf::Color(0, 0, 0, 255)) { }