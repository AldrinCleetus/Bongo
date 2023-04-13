#pragma once

#include "SFML/Graphics.hpp"

class Collider
{

public:
	sf::RectangleShape collider;
	bool collision = false;

	sf::FloatRect collisionIntersection;
	sf::Vector2f collisionResponseMoveAmount;

public:
	Collider(sf::Vector2f size, sf::Vector2f position);

	void render(sf::RenderTarget& target);
	void update(sf::Vector2f position);

	bool isColliding(Collider& collidingObject);
	bool isColliding(sf::RectangleShape& collidingObject);

	sf::Vector2f collisionResponse(sf::RectangleShape& collidingObject);



};

