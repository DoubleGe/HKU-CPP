
#include <iostream>
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <cmath>


void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(circle);
}

void Circle::SetPosition(Vector2 position)
{
	this->position = position;
	circle.setPosition(position.x, position.y);
}

float Circle::CalcArea()
{
	return 3.14f * radius * radius;
}

void Circle::SetColor(sf::Color color)
{
	circle.setFillColor(color);
}

void Circle::SetRadius(float radius)
{
	this->radius = radius;
	circle.setRadius(radius);
}

//Circle::Circle(int x, int y, float r)
//{
//	circle = sf::CircleShape(100);
//	SetPosition(xPos, yPos);
//	SetRadius(10);
//	circle.setFillColor(sf::Color(255, 0, 0, 255));
//}

