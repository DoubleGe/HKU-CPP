#include "Rectangle.h"

void SR::Rectangle::SetPosition(Vector2 position)
{
	this->position = position;
	rectangle.setPosition(position.x, position.y);
}

void SR::Rectangle::Draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

float SR::Rectangle::CalcArea()
{
	return size.x * size.y;
}

void SR::Rectangle::SetColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

void SR::Rectangle::SetSize(Vector2 size)
{
	this->size = size;
	rectangle.setSize(size.ConvertToSFML());
}

Vector2 SR::Rectangle::GetSize()
{
	return size;
}

void SR::Rectangle::SetSize(float xSize, float ySize)
{
	SetSize(Vector2(xSize, ySize));
}
