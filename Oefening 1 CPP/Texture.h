#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class Texture : public Shape
{
private:

public:
	sf::Texture texture;
	sf::Sprite sprite;

	void SetPosition(Vector2 position);
	void Draw(sf::RenderWindow& window);

	Texture(sf::String path);
};

