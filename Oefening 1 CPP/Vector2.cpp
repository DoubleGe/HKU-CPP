#include "Vector2.h"
#include <cmath>

float Vector2::GetLength()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalized()
{
	return Vector2(x / GetLength(), y / GetLength());
}

Vector2 Vector2::UnitVector()
{
	return Vector2();
}

float Vector2::DotProduct(Vector2 vec)
{
	return x * vec.x + y * vec.y;
}

float Vector2::NormalizedDotProduct(Vector2 vec)
{
	Vector2 norm = Normalized();
	Vector2 newNorm = vec.Normalized();

	return norm.x * newNorm.x + norm.y * newNorm.y;
}

sf::Vector2<float> Vector2::ConvertToSFML()
{
	return sf::Vector2<float>(x, y);
}


