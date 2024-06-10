
#include <iostream>
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <cmath>


//Draws the Cirlce.
void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(circle);
}

//Sets the position of the circle.
void Circle::SetPosition(Vector2 position)
{
	this->position = position;
	circle.setPosition(position.x, position.y);
}

//Calculate the Area of the circle.
float Circle::CalcArea()
{
	return 3.14f * radius * radius;
}

//Set Circle Color
void Circle::SetColor(sf::Color color)
{
	circle.setFillColor(color);
}

//Set Circle Radius
void Circle::SetRadius(float radius)
{
	this->radius = radius;
	circle.setRadius(radius);
}