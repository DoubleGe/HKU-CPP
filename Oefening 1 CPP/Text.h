#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include "iostream"
//#include "Game.h"

class Text : public Shape
{
private:
	sf::Text textObj;
	sf::String text;
	//sf::Font& font;

	static sf::Font defaultFont;

public:
	void Draw(sf::RenderWindow& window);
	void SetPosition(Vector2 position);
	void SetColor(sf::Color color);
	void SetText(sf::String text);

	Text(Vector2 position, sf::Color color, sf::String text) : Shape(position.x, position.y, color)
	{
		textObj = sf::Text();

		this->text = text;
		textObj.setString(text);
		textObj.setCharacterSize(24);

		SetColor(color);
		textObj.setFont(defaultFont);
		SetPosition(position);
	};

	Text() : Shape(0, 0, sf::Color(0, 0, 0, 255)) {
		textObj = sf::Text();

		text = "";
		textObj.setString(text);
		textObj.setCharacterSize(24);
		textObj.setFont(defaultFont);
		SetPosition(Vector2(0, 0));
	}

	static void LoadDefaultFont(const std::string& fontPath);
};