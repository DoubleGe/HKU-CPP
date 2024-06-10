#include "Rectangle.h"

//Sets position of the Rectangle.
void SR::Rectangle::SetPosition(Vector2 position)
{
	this->position = position;
	rectangle.setPosition(position.x, position.y);
}

//Draws Rectangle.
void SR::Rectangle::Draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

//Calculates Rectangle Size.
float SR::Rectangle::CalcArea()
{
	return size.x * size.y;
}

//Sets Color.
void SR::Rectangle::SetColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

//Sets the Rectangle Size Using vector2.
void SR::Rectangle::SetSize(Vector2 size)
{
	this->size = size;
	rectangle.setSize(size.ConvertToSFML());
}

//Gets the Rectangle Size.
Vector2 SR::Rectangle::GetSize()
{
	return size;
}

//Set Rectangle Size.
void SR::Rectangle::SetSize(float xSize, float ySize)
{
	SetSize(Vector2(xSize, ySize));
}
