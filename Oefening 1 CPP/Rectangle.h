#pragma once
#include "Shape.h"

namespace SR {
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
		Vector2 GetSize();

		Rectangle() : Shape(0, 0, sf::Color(255, 255, 255, 255)) {
			rectangle = sf::RectangleShape();

			SetSize(Vector2(10, 10));
		};
		Rectangle(float xPos, float yPos, sf::Color color, Vector2 size) : Shape(xPos, yPos, color) {
			rectangle = sf::RectangleShape();

			SetSize(size);
			//SetPosition(Vector2(xPos, yPos));
			SetColor(color);
		};

		void SetSize(sf::Vector2<float> size);
		void SetSize(float xSize, float ySize);
	};
}