#pragma once

#include "SFML/Graphics.hpp"
#include "collider.h"


class Test_object
{
public:
	sf::RectangleShape shape;
	Collider* myCollider;

	Test_object();

	void init();
	void update();
	void render(sf::RenderTarget& target);
};

