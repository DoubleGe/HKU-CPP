#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Shape
{
protected:
	sf::Color color;
public:
	Vector2 position;
	virtual void SetPosition(float xPos, float yPos);
	virtual void SetPosition(Vector2 position);

	virtual void Draw(sf::RenderWindow& window);
	virtual void SetColor(sf::Color color);
	virtual float CalcArea();

	Shape(float xPos, float yPos, sf::Color color) : position(xPos, yPos){
		SetPosition(xPos, yPos);
		SetColor(color);
	};
};

