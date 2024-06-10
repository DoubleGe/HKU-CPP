#include "Vector2.h"
#include <cmath>

const Vector2 Vector2::UP(0, 1);
const Vector2 Vector2::DOWN(0, -1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);

//Gets the length of the vector2
float Vector2::GetLength()
{
	return sqrt(x * x + y * y);
}

//Normalizes the vector2
Vector2 Vector2::Normalized()
{
	return Vector2(x / GetLength(), y / GetLength());
}

//Returns the dot product of the vector2
float Vector2::DotProduct(Vector2 vec)
{
	return x * vec.x + y * vec.y;
}

//Normalized Dot product.
float Vector2::NormalizedDotProduct(Vector2 vec)
{
	Vector2 norm = Normalized();
	Vector2 newNorm = vec.Normalized();

	return norm.x * newNorm.x + norm.y * newNorm.y;
}

//Converts the Vector2 to a Vector2 supported by the SFML lib.
sf::Vector2f Vector2::ConvertToSFML()
{
	return sf::Vector2f(x, y);
}