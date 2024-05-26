#include "Text.h"
#include "Windows.h"

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
void Text::LoadFont()
{
	sf::Font font;

	std::string fontPath = GetExecutablePath() + "\\arial.ttf";
	if (!font.loadFromFile(fontPath))
	{

	}
}
std::string Text::GetExecutablePath()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}
//
//Text::Text(float x, float y, sf::Color color, sf::String text) : Shape(x, y, color)
//{
//	textObj = sf::Text();
//	textObj.setString(text);
//	SetPosition(Vector2(x, y));
//}