#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Draw(sf::RenderWindow& window);
	virtual void Remove();
};

