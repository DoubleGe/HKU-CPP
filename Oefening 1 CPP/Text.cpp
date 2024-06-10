#include "Text.h"
sf::Font Text::defaultFont;

void Text::Draw(sf::RenderWindow& window)
{
	window.draw(textObj);
}

void Text::SetPosition(Vector2 position)
{
	textObj.setPosition(position.ConvertToSFML());
}

void Text::SetColor(sf::Color color)
{
	textObj.setFillColor(color);
}

//Set the text content.
void Text::SetText(sf::String text)
{
	this->text = text;
	textObj.setString(text);
}

//Set Text bold
void Text::SetBold(bool bold)
{
	if (bold) textObj.setStyle(sf::Text::Bold);
	else textObj.setStyle(0);
}

//Set Text Size.
void Text::SetSize(int size)
{
	textObj.setCharacterSize(size);
}

//Loads the default 
void Text::LoadDefaultFont(const std::string& fontPath)
{
	if (!defaultFont.loadFromFile(fontPath))
	{
		std::cerr << "Failed to load default font from " << fontPath << std::endl;
	}
}