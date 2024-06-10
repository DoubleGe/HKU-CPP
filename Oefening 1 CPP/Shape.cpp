#include "Shape.h"
#include <iostream>

//BASE/SUPER CLASS FUNCTIONS

void Shape::SetPosition(float xPos, float yPos)
{
	SetPosition(Vector2(xPos, yPos));
}

void Shape::SetPosition(Vector2 position)
{
}

void Shape::SetColor(sf::Color color)
{
	this->color = color;
}

float Shape::CalcArea()
{
	return 0.0f;
}

