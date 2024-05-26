#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include "iostream"

class Text : public Shape
{
private:
	sf::Text textObj;
	sf::Font font;

public:
	void Draw(sf::RenderWindow& window);
	void SetPosition(Vector2 position);
	void SetColor(sf::Color color);

	Text(float x, float y, sf::Color color, sf::String text) : Shape(x, y, color)
	{
		textObj = sf::Text();
		textObj.setString(text);
		textObj.setCharacterSize(24);
		SetColor(color);
		LoadFont();
		textObj.setFont(font);
		SetPosition(Vector2(x, y));
	};

	Text() : Shape(0, 0, sf::Color(0, 0, 0, 255)) {
		textObj = sf::Text();
		textObj.setString("");
		SetPosition(Vector2(0, 0));
	}

	void LoadFont();

	std::string GetExecutablePath();
};