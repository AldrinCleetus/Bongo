#pragma once

#include "SFML/Graphics.hpp"

class Collider
{

public:
	sf::RectangleShape collider;

public:
	Collider(sf::Vector2f size);

	void render(sf::RenderTarget& target);
	void update(sf::Vector2f position);

	bool isColliding(sf::RectangleShape& collidingObject);


};

