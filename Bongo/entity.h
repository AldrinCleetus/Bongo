#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Entity
{
public:
	sf::Vector2f position;
	sf::Vector2f scale;


public:
	Entity();
	virtual ~Entity();

	virtual void update();
	virtual void render(sf::RenderTarget& target);
	
	void move(sf::Vector2f movePosition);
	void setPosition(sf::Vector2f position);
	void setScale(sf::Vector2f scale);
};

