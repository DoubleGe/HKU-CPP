#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	sf::RectangleShape rectangle;
	Vector2 size;
public:
	void SetPosition(Vector2 position);

	void Draw(sf::RenderWindow& window);
	void SetColor(sf::Color color);
	float CalcArea();
	void SetSize(Vector2 size);

	Rectangle(float xPos, float yPos, sf::Color color, Vector2 size) : Shape(xPos, yPos, color) {
		this->size = size;
		rectangle = sf::RectangleShape();

		SetSize(size);
		SetPosition(Vector2(xPos, yPos));
		SetColor(color);
	};

	void SetSize(sf::Vector2<float> size);
	void SetSize(float xSize, float ySize);
};

