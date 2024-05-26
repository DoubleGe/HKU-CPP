#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:
	sf::CircleShape circle;
	float radius;
public:
	void Draw(sf::RenderWindow& window);
	void SetPosition(Vector2 position);

	float CalcArea();
	void SetColor(sf::Color color);
	void SetRadius(float radius);

	Circle(float x, float y, sf::Color color,  float r) : Shape(x, y, color), radius(r)
	{
		circle = sf::CircleShape(r);
		SetPosition(Vector2(x, y));
		SetColor(color);
	};
};

