#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector2
{
public:
	float x;
	float y;
	
	Vector2 Normalized();
	float GetLength();
	Vector2 UnitVector();
	float DotProduct(Vector2 vec);
	float NormalizedDotProduct(Vector2 vec);
	sf::Vector2f ConvertToSFML();

	Vector2() : x(0), y(0) {};
	Vector2(float x, float y) : x(x), y(y) {};
	//static Vector2 min(Vector2 vec1, Vector2 vec2);

	//Operators
	Vector2 operator+ (const Vector2& vecToAdd) {
		return Vector2(x + vecToAdd.x, y + vecToAdd.y);
	};

	Vector2 operator- (const Vector2& vecToAdd) {
		return Vector2(x - vecToAdd.x, y - vecToAdd.y);
	};

	Vector2 operator* (const float multiply) {
		return Vector2(x * multiply, y * multiply);
	}

	Vector2 operator/ (const float devide) {
		return Vector2(x / devide, y / devide);
	}

	void operator+= (const Vector2& vecToAdd) {
		x += vecToAdd.x;
		y += vecToAdd.y;
	}

	void operator-= (const Vector2& vecToAdd) {
		x -= vecToAdd.x;
		y -= vecToAdd.y;
	}

	friend std::ostream& operator<<(std::ostream& strm, const Vector2& a);
};

