#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class Texture : public Shape
{
private:

public:
	sf::Texture texture;
	sf::Sprite sprite;
	Vector2 size;

	void SetPosition(Vector2 position);
	void SetSize(Vector2 size);
	void Draw(sf::RenderWindow& window);

	Texture(sf::String path, Vector2 position);
	Texture(sf::String path);
	Texture();
};

