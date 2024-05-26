#include "Rectangle.h"

void Rectangle::SetPosition(Vector2 position)
{
	this->position = position;
	rectangle.setPosition(position.x, position.y);
}

void Rectangle::Draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

float Rectangle::CalcArea()
{
	return size.x * size.y;
}

void Rectangle::SetColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

void Rectangle::SetSize(Vector2 size)
{
	this->size = size;
	rectangle.setSize(size.ConvertToSFML());
}

void Rectangle::SetSize(float xSize, float ySize)
{
	SetSize(Vector2(xSize, ySize));
}
